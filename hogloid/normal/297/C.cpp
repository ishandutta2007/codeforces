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
pi s[100005];
int ar[100005];
int resA[100005],resB[100005];
int main(){
	cin>>n;
	REP(i,n){
		scanf("%d",&s[i].fr);
		s[i].sc=i;
		ar[i]=s[i].fr;
	}
	sort(s,s+n);
	int n3=(n+2)/3;
	REP(i,n3){
		int p=s[i].sc;
		resA[p]=0;
	}

	REPN(i,min(n,n3*2),n3){
		int p=s[i].sc;
		resA[p]=n3+(i-n3);
	}

	REPN(i,n,n3*2){
		int p=s[i].sc;
		resA[p]=-(i-n3*2)+n3-1;
	}

	REP(i,n) resB[i]=ar[i]-resA[i];

	puts("YES");
	REP(i,n) printf("%d ",resA[i]);
	puts("");
	REP(i,n) printf("%d ",resB[i]);
	puts("");
	return 0;
}