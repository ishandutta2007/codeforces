#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5,mo=1e9+7;
int t;
ll n;
ll _[1000];
struct nod{
	ll a[3];
	nod(ll x=0,ll y=0,ll z=0){a[0]=x;a[1]=y;a[2]=z;}
};
void get_k(ll n,int k,nod &f){
	f.a[0]=1LL<<(k-2);
	f.a[1]=1LL<<(k-1);
	f.a[2]=(1LL<<(k-1))+(1LL<<(k-2));
	--n;
	for(int i=k-2;k>=2;k-=2){
		int o=n>>k-2&3;
		ll v1=1LL<<(k-2),v2=1LL<<(k-1),v3=v1+v2;
		if(o==1)f.a[0]+=v1,f.a[1]+=v2,f.a[2]+=v3;
		if(o==2)f.a[0]+=v2,f.a[1]+=v3,f.a[2]+=v1;
		if(o==3)f.a[0]+=v3,f.a[1]+=v1,f.a[2]+=v2;
	}
}
nod get(ll n){
	int k=lower_bound(_,_+31,n*3+1)-_;
	n-=((1LL<<(k+k-2))-1)/3;
	nod f=nod();
	get_k(n,k+k,f);
	return f;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	fo(i,0,30)_[i]=1LL<<(i+i);
	for(;t--;){
		cin>>n;
		--n;
		printf("%lld\n",get(n/3+1).a[n%3]);
	}
}