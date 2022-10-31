#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))
#define N 10005

ll i,j,k,n,m,t,a[1050],b[1050],su;
bool f[20050],g[20050];
ll res,r1,r2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		su=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			res+=(n-2ll)*a[i]*a[i];
			su+=a[i];
		}
		for(i=1;i<=n;i++){
			cin>>b[i];
			res+=(n-2ll)*b[i]*b[i];
			su+=b[i];
		}
		for(i=1;i<=n;i++){
			if(a[i]>b[i]){
				swap(a[i],b[i]);
			}
		}
		memset(f,0,sizeof(f));
		f[N]=1;
		for(i=1;i<=n;i++){
			memset(g,0,sizeof(g));
			for(j=-(i-1)*100;j<=(i-1)*100;j++){
				g[j+a[i]-b[i]+N]|=f[N+j];
				g[j-a[i]+b[i]+N]|=f[N+j];
			}
			memcpy(f,g,sizeof(f));
		}
		for(i=0;;i++){
			if(f[N+i]||f[N-i]){
				r1=(su+i)/2;
				r2=(su-i)/2;
				break;
			}
		}
		//printf("NMSL%d %d\n",r1,r2);
		res+=r1*r1+r2*r2;
		cout<<res<<'\n';
	}
}