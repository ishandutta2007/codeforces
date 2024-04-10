#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-15;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define int ll

int num=0;
int a[5010],p[5010];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}

signed main(){
	int tc;
	scanf("%lld",&tc);
	while(tc--){
		iota(p,p+5010,0);

		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
			if(a[i]==1)p[i]=i+1;
		}
		int ans=0;
		while(1){
			int fir=0;
			for(int i=1;i<=n;i++)if(a[i]>1){
				fir=i;
				break;
			}
			if(!fir)break;
			ans+=max(0LL,a[fir]-(n+1-fir));
			a[fir]=min(a[fir],n+1-fir);
			while(a[fir]!=1){
				for(int i=fir;i<=n;){
					int nxt=i+a[i];
					a[i]--;
					if(a[i]<1)a[i]=1;
					if(a[i]==1){
						p[i]=i+1;
					}
					nxt=min(nxt,n+1);
					i=f(nxt);
				}
				//for(int i=1;i<=n;i++)cerr<<a[i]<<" ";
				//cerr<<endl;
				ans++;
			}
			if(!fir)break;
		}
		printf("%lld\n",ans);
	}
}