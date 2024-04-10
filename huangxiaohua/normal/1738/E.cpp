#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 998244353 

ll i,j,k,n,m,t,res;

ll jc[1005000],inv[1005000];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(ll n,ll m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

ll pl[100005],pr[100005],a[100005],f[100005],cur,t1,t2,t3;

int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		map<ll,ll> mp,mpl,mpr,ty;
		
		for(i=1;i<=n;i++){
			cin>>a[i];
			pl[i]=pl[i-1]+a[i];
		}
		
		pr[n+1]=0;
		for(i=n;i>=1;i--){
			pr[i]=pr[i+1]+a[i];
			mp[pr[i]]++;
		}
		
		for(i=1;i<=n;i++){
			mp[pr[i]]--;
			if(pl[i]<pr[i]){
				mpl[pl[i]]++;
				mpr[pl[i]]=mp[pl[i]];
				ty[pl[i]]=1;
			}
			else if(pl[i]==pr[i]){
				if(pl[i]&&!a[i])mp[pl[i]]++;
				mpr[pl[i]]=mpl[pl[i]]=mp[pl[i]]+1;
				
				ty[pl[i]]=2;
				break;
			}
			else break;
		}
		
		res=1; t1=1; t2=0;
		
		for(auto [w,num]:mpl){
			//printf("NMSL%d %d %d %d\n",w,num,mpr[w],ty[w]);
			if(!ty[w])break;
			
			if(ty[w]==1){
				for(i=1;i<=num;i++){
					res=su(res,c(num,i)*c(mpr[w],i)%M*t1%M);
				}
				t1=res;
			}
			else{
				res=su(res,(ksm(2,num-1)-1)*t1%M);
				break;
			}
		}
		
		cout<<res<<'\n';
	}
}