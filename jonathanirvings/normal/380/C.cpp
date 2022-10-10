//Codeforces Round #223 (Div. 1)
//12 Jan 2013

//start of jonathanirvings' template v2.0.0 (BETA)

#define jonathan using
#define ganteng namespace
#define banget std
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <time.h>
#include <bitset>
#include <list>
jonathan ganteng banget;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
	#define DEBUG fprintf(stderr,"====TESTING====\n")
	#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define DEBUG 
	#define VALUE(x)
	#define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline string uppercase(string s){
	int n = SIZE(s); 
	REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s); 
	REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	return s;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v2.0.0 (BETA)

typedef struct 
{
	int val;
	//int aL,aR,bL,bR;
	int aP,bP;
} gajah;

string s;
int n,t,a,b;
gajah tree[5000005];

//gajah gen(int a,int b,int c,int d,int e)
gajah gen(int a,int b,int c)
{
	gajah tmp;
	//tmp.val = a; tmp.aL = b; tmp.aR = c; tmp.bL = d; tmp.bR = e;
	tmp.val = a; tmp.aP = b; tmp.bP = c;
	return tmp;
}

void build(int ix,int L,int R)
{
	if (L == R)
	{
		if (s[L] == '(')
			tree[ix] = gen(0,1,0);
		else tree[ix] = gen(0,0,1);
		return;
	}
	int M = (L + R) >> 1;
	build(ix*2+1,L,M);
	build(ix*2+2,M+1,R);
	tree[ix].val = tree[ix*2+1].val + tree[ix*2+2].val + min(tree[ix*2+1].aP,tree[ix*2+2].bP);
	tree[ix].aP = tree[ix*2+1].aP + tree[ix*2+2].aP - min(tree[ix*2+1].aP,tree[ix*2+2].bP);
	tree[ix].bP = tree[ix*2+1].bP + tree[ix*2+2].bP - min(tree[ix*2+1].aP,tree[ix*2+2].bP);
	//printf("%d %d %d %d %d\n",L,R,tree[ix].val,tree[ix].aP,tree[ix].bP);
}

gajah query(int ix,int L,int R,int x,int y)
{
	if (x <= L && R <= y) return tree[ix];
	if (x > R || y < L) return gen(-1,-1,-1);
	int M = (L + R) >> 1;
	gajah tmp1 = query(ix*2+1,L,M,x,y),tmp2 = query(ix*2+2,M+1,R,x,y);
	if (tmp1.val == -1) return tmp2;
	if (tmp2.val == -1) return tmp1;
	gajah tmp3;
	tmp3.val = tmp1.val + tmp2.val + min(tmp1.aP,tmp2.bP);
	tmp3.aP = tmp1.aP + tmp2.aP - min(tmp1.aP,tmp2.bP);
	tmp3.bP = tmp1.bP + tmp2.bP - min(tmp1.aP,tmp2.bP);
	return tmp3;
}

int main()
{
	s = GetString();
	n = SIZE(s);
	scanf("%d",&t);
	build(0,0,n-1);
	TC(t)
	{
		scanf("%d %d",&a,&b);
		gajah risan = query(0,0,n-1,a-1,b-1);
		printf("%d\n",risan.val * 2);
	}
	return 0;
}