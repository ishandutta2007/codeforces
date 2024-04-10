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
int n,m,k;
pi es[100005];
int mark[1000005];
const lint mod=1000000007;

lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

int solve(){
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		if(a+1!=b){
			es[cnt++]=mp(a,b);
			if(b-a!=k+1) return 0;
		}
	}
	sort(es,es+cnt);
	if(cnt && es[0].sc<=es[cnt-1].fr) return 0;

	if(cnt==0){
		lint res=0;
		REP(i,n-k-1){
			int r=min(i+k+1,n-k-1);
			res=(res+mpow(2,r-i-1))%mod;
		}
		res=(res+1)%mod;
		return res;
	}
	lint res=0;
	REP(i,n-k-1){
		int r=min(i+k+1,n-k-1);
		if(es[0].fr<i || r<=es[cnt-1].fr) continue;
		int expo=(r-i)-cnt;
		if(es[0].fr!=i) --expo;
		res=(res+mpow(2,expo))%mod;
	}
	return res;
}


int main(){
	printf("%d\n",solve());


	return 0;
}