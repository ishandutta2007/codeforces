#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
lint ar[10];
int fcnt[10];
int memo[1<<15];
int divisor[1<<10][10];
int rec(int bit){//2:: full 1::referred only 0::unavailable
	int& res=memo[bit];
	if(res!=-1) return res;
	int state[10];
	int bibit=0;
	int pbit=bit;
	REP(i,n) state[i]=bit%3,bit/=3;
	REP(i,n) if(state[i]) bibit|=(1<<i);
	
	if(__builtin_popcount(bibit)==1) return 1;
	res=0;
	REP(i,1<<n) if(!((~bibit)&i)) {
		int worth=0;
		int rest=i^bibit;
		REP(j,n) if(i>>j&1) worth+=fcnt[j];
		REP(j,n) if(state[j]==2 && divisor[i][j] && rest>>j&1){
			int nbit=0;
			for(int k=n-1;k>=0;--k){
				if(state[k]==0 || i>>k&1) ;
				else if(state[k]==1 || k==j) nbit++;
				else nbit+=2;
				nbit*=3;
			}
			nbit/=3;
			res=max(res,rec(nbit)+worth);
		}
	}
	return res;
}

int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	REP(i,n){
		lint tmp=ar[i];
		for(lint j=2;j*j<=tmp;++j){
			while(tmp%j==0){
				++fcnt[i];
				tmp/=j;
			}
		}
		if(tmp>1) ++fcnt[i];
	}

	REP(i,1<<n){
		double mul=1;
		lint mul2=1;
		REP(j,n) if(i>>j&1) mul*=ar[j],mul2*=ar[j];
		REP(j,n) if(mul<1e18 && ar[j]%mul2==0) divisor[i][j]=1;
	}

	memset(memo,-1,sizeof(memo));
	int tmp=0;
	REP(i,n) tmp+=2,tmp*=3;
	tmp/=3;
	int res=rec(tmp);
	
	int base=0;
	REP(i,n){
		base+=fcnt[i]+1;
		if(fcnt[i]==1) --base;
	}
	++base;
	printf("%d\n",base-res);

	return 0;
}