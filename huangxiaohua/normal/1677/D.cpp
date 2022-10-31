#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,a[1005000],l[1005000],r[1005000];
ll jc[1005000],inv[1005000],res;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++){
			if(a[i]>=i){
				cout<<"0\n";goto aaa;
			}
		}
		for(i=n-m+1;i<=n;i++){
			if(a[i]!=-1&&a[i]!=0){
				cout<<"0\n";goto aaa;
			}
		}
		for(i=n;i>=1;i--){
			if(i>m){
				a[i]=a[i-m];
				if(a[i]==-1)l[i]=0,r[i]=i-1;
				else if(a[i]==0)l[i]=0,r[i]=m;
				else l[i]=r[i]=a[i]+m;
			}
			else{
				l[i]=0,r[i]=i-1;
			}
		}
		res=1;
		for(i=1;i<=n;i++){
			//printf("a%d %d\n",l[i],r[i]);
			r[i]=min(r[i],i-1);
			l[i]=min(l[i],i);
			res=res*(r[i]-l[i]+1)%M;
		}
		cout<<res<<'\n';
		
		aaa:;
	}
}