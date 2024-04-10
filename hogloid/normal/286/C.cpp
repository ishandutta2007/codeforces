#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int stk[1000005];
int p[1000005],neg[1000005];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]);
	int m;scanf("%d",&m);
	REP(i,m){
		int a;scanf("%d",&a);
		--a;
		neg[a]=1;
	}
	m=0;
	for(int i=n-1;i>=0;--i){
		if(neg[i]) stk[m++]=p[i];
		else{
			if(m>0 && stk[m-1]==p[i]) --m;
			else neg[i]=1,stk[m++]=p[i];
		}
	}

	if(m>0) puts("NO");
	else{
		puts("YES");
		REP(i,n) printf("%d\n",(neg[i]?-1:1)*p[i]);
	}

	return 0;
}