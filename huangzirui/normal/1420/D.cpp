#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=600010,mod=998244353;
struct node{
	int t,s;
}a[maxn];
bool cmp(node a,node b){
	return a.t<b.t || (a.t==b.t && a.s>b.s);
}
int i,j,k,n,m,cnt;ll jc[maxn],ans;
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
ll C(ll x,ll y){
	if(x<y)return 0;
//	cout<<"C "<<x<<' '<<y<<" ="<<jc[x]<<" "<<ksm(jc[y],mod-2)%mod*ksm(jc[x-y],mod-2)%mod<<endl;
	return jc[x]*ksm(jc[y],mod-2)%mod*ksm(jc[x-y],mod-2)%mod;
}
int main(){
	cin>>n>>m;
	jc[0]=1;for(i=1;i<=n*2;i++)jc[i]=jc[i-1]*i%mod;
	for(i=1;i<=n;i++)a[++cnt]={read(),1},a[++cnt]={read(),-1};
	sort(a+1,a+1+cnt,cmp);
	ll sum=0;
	for(i=1;i<=cnt;i++){
		if(a[i].s<0)sum--;
		else{
			ans=(ans+C(sum,m-1))%mod;
			sum++;
		}
//		cout<<"i="<<i<<" t="<<a[i].t<<' '<<sum<<' '<<ans<<endl;
	}cout<<ans<<endl;
	return 0;
}