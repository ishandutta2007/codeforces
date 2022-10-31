#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[200500],b[200500],c[200500],d[200500],e[200500],mx,mn,l,r;
char s[200500];
int main() {
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>s+1;
		c[n+1]=d[n+1]=0;
		mx=mn=k=0;
		for(i=1;i<=n;i++){
			k+=(s[i]=='+'?1:-1);
			mx=max(mx,k);mn=min(mn,k);
			a[i]=mx;b[i]=mn;
			e[i]=k;
		}
		mx=mn=k=0;
		for(i=n;i>=1;i--){
			k+=(s[i]=='+'?-1:1);
			mx=max(mx,k);mn=min(mn,k);
			c[i]=mx-k;d[i]=mn-k;
		}
		while(m--){
			cin>>l>>r;
			mx=max(a[l-1],e[l-1]+c[r+1]);
			mn=min(b[l-1],e[l-1]+d[r+1]);
			//printf("NMSL%d %d\n",mx,mn);
			cout<<mx-mn+1<<'\n';
		}
	}
}