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
lint k,w;
lint mod=1000000007;
lint inv[1000005];
lint factorial[1000005];
lint invfact[1000005];
lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}
int main(){
	inv[1]=1;
	for(int i=2;i<1000005;++i) inv[i]=(-inv[mod%i]*(mod/i)%mod+mod)%mod;
	factorial[0]=1;
	invfact[0]=1;
	REP(i,1000005-1){
		factorial[i+1]=factorial[i]*(i+1)%mod;
		invfact[i+1]=invfact[i]*inv[i+1]%mod;
	}
	cin>>k>>w;
	lint ans=0;
	for(int t=1;t<=k;++t){
		lint a=0,b=0;
		if(t<w)	a=factorial[k]*factorial[k]%mod*t%mod*mpow(k,w-t-1)%mod
				*invfact[k-t]%mod*invfact[k-t]%mod;
		else a=factorial[k]*factorial[k-t+w-1]%mod*w%mod*invfact[k-t]%mod
				*invfact[k-t]%mod;
		if(k-t-1>=0){
			if(t<w-1) b=factorial[k]*factorial[k]%mod*t%mod*mpow(k,w-t-2)%mod
					*invfact[k-t]%mod*invfact[k-t-1]%mod;
			else b=factorial[k]*factorial[k-t+w-2]%mod*(w-1)%mod
				*invfact[k-t]%mod*invfact[k-t-1]%mod;
		}
		ans+=a+b;
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}