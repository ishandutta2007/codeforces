#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define cls(x) memset(x,0,sizeof x)
#define cpy(x,y) memcpy(x,y,sizeof y)
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
#define ll long long
#define ul unsigned ll
#define ui unsigned int
#define db double
#define ldb long double
#define bit(x,y)((x)>>(y)&1)
using namespace std;
const int N=5e5+5;
int n,k;
ll c[N];
ll ans,sum,tot;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&k);
	fo(i,1,n)scanf("%lld",&c[i]);
	k=min(k,n);
	sort(c+1,c+n+1);
	if(k==0){
		fd(i,1,n){
			tot+=sum;sum+=c[i];
		}
		ans=tot;
	}else{
		fd(i,1,n){
			if(sum+c[i]>=0){
				tot+=sum;sum+=c[i];
			}else{
				tot+=sum;
				if(i==1)ans=tot;else{
					ans=tot;
					c[i]+=sum;
					fo(j,1,i){
						int s=(j-1)/(k+1);
						ans+=(ll)c[j]*s;
					}
				}
				printf("%lld\n",ans);
				exit(0);
			}
		}
		ans=tot;
	}
	printf("%lld\n",ans);
}