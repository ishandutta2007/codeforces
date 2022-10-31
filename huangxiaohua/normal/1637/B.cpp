#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,a[105],f[105],mex[105][105],g[205];
ll res=0;
int get(int l,int r){
	int i,j,k,m;
	m=0;
	memset(f,0,sizeof(f));
	for(i=l;i<=r;i++){
		f[i]=mex[l][i]+1;
		for(j=i-1;j>=l;j--){
			f[i]=max(f[i],f[j]+1+mex[j+1][i]);
		}
	}
	return f[r];
}
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			a[i]=min(a[i],200);
		}
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				memset(g,0,sizeof(g));
				for(k=i;k<=j;k++){
					g[a[k]]++;
				}
				for(k=0;;k++){
					if(!g[k]){
						mex[i][j]=k;break;
					}
				}
			}
		}
		res=0;
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				res+=get(i,j);
			}
		}
		cout<<res<<'\n';
	}
}