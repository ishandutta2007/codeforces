#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
ll i,j,k,n,m,t;
ll a[200500],b[200500],pos[200500],nmsl[200500],res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=1;
		for(i=1;i<=n;i++){
			cin>>a[i];nmsl[i]=0;
		}
		for(i=1;i<=n;i++){
			cin>>b[i];
			if(b[i]==-1)b[i]=0;
			pos[a[i]]=b[i];
			if(pos[a[i]]&&pos[a[i]]+m<a[i])res=0;
			nmsl[pos[a[i]]]=1;
		}
		int NMSL=0;
		for(i=1;i<=m;i++){
			NMSL+=!pos[i];
		}
		for(i=1;i<=n;i++){
			if(i+m<=n)NMSL+=!pos[i+m];
			if(!nmsl[i]){
				res=res*NMSL%M;NMSL--;
			}
		}
		cout<<res<<'\n';
	}
}