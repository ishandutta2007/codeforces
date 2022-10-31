#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t;
ll l[200500],r[200500],p[200500],x[200500],y[200500],len[200500],t1,t2,t3,res,f1,cx,cy,fx,fy;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>l[i];
	for(i=1;i<=n;i++)cin>>r[i];
	for(i=1;i<=n;i++){
		x[i]=(r[i]-l[i]+1)*(r[i-1]-l[i-1]+1)%M;
		y[i]=max(0ll,min(r[i],r[i-1])-max(l[i],l[i-1])+1);
		p[i]=(x[i]+M-y[i])%M*ksm(x[i],M-2)%M;
	}
	res=f1=fx=fy=1;
	for(i=1;i<n;i++){
		t1=max(0ll,min({r[i-1],r[i],r[i+1]})-max({l[i-1],l[i],l[i+1]})+1);
		t2=max(0ll,min({r[i],r[i+1]})-max({l[i],l[i+1]})+1);
		res+=f1+f1+1+M-t1*(fx+fx+1)%M*ksm(x[i+1],M-2)%M+M-(t2-t1)*(fy+fy+1)%M*ksm(x[i+1],M-2)%M;res%=M;
		fx=(f1+1-ksm(r[i]-l[i]+1,M-2)+M)%M;fy=f1+1;f1=su(f1,p[i+1]);
	}
	cout<<res%M;
}