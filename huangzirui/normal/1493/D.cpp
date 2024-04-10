#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010,mod=1e9+7;
int i,j,k,n,m,T,a[maxn],prime[maxn],is_prime[maxn],cnt,id[maxn];
map<int,int>V[maxn];
map<int,int>::iterator it;
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
void init(){
	for(int i=2;i<maxn;i++)is_prime[i]=1;
	for(int i=2;i<maxn;i++){
		if(is_prime[i])prime[++cnt]=i,id[i]=cnt;
		for(int j=1;j<=cnt && prime[j]*i<maxn;j++){
			is_prime[prime[j]*i]=0;
			if(i%prime[j]==0)break;
		}
	}
}
multiset<int>S[maxn];
int ans[maxn];
ll Ans=1;
int getsum(int id){
//	cout<<"GETSUM "<<id<<' '<<S[id].size()<<endl;
	return S[id].size()!=n?1:ksm(prime[id],*S[id].begin());
}
void make(int x,int y){
//	cerr<<"MAKE "<<x<<' '<<y<<endl;
	for(int i=1;prime[i]<=sqrt(x);i++){
		int num=0;
		while(x%prime[i]==0){
			x/=prime[i];
			++num;
		}
		if(num){
			int last=V[y][i];
//			cerr<<"last="<<last<<' '<<num<<endl;
			Ans*=ksm(getsum(i),mod-2);
			Ans%=mod;
			if(last)S[i].erase(S[i].find(last));
			V[y][i]+=num;
			S[i].insert(V[y][i]);
			Ans*=getsum(i);
			Ans%=mod;
//			cerr<<"OK"<<endl;
		}
	}
	if(x!=1){
		int last=V[y][id[x]];
		Ans*=ksm(getsum(id[x]),mod-2);
		Ans%=mod;
		if(last)S[id[x]].erase(S[id[x]].find(last));
		V[y][id[x]]++;
		S[id[x]].insert(V[y][id[x]]);
		Ans*=getsum(id[x]);
		Ans%=mod;
	}
}
int main(){
	cin>>n>>m;
	init();
	for(i=1;i<=n;i++){
		a[i]=read();
		make(a[i],i);
	}
//	for(i=1;i<=cnt;i++){
//		if(S[i].size()==n){
//			int x=*S[i].begin();
//			Ans*=ksm(prime[i],x);
//			cout<<prime[i]<<' '<<x<<endl;
//			Ans%=mod;
//		}
//	}
	for(i=1;i<=m;i++){
		int x=read(),y=read();
		make(y,x);
		printf("%lld\n",Ans);
	}
	return 0;
}