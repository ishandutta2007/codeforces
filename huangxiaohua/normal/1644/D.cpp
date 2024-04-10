#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,x[200500],y[200500],nn;
bool vx[200500],vy[200500];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		int q;
		cin>>n>>nn>>m>>q;
		ll res=1;
		for(i=1;i<=max(n,nn);i++){
			vx[i]=vy[i]=0;
		}
		for(i=1;i<=q;i++){
			cin>>x[i]>>y[i];
		}
		for(i=q;i>=1;i--){
			if(!vx[x[i]]||!vy[y[i]]){
				res=res*m%M;
			}
			if(!vx[x[i]]){
				n--;
				vx[x[i]]=1;
			}
			if(!vy[y[i]]){
				nn--;
				vy[y[i]]=1;
			}
			//printf("NMSL%d %d\n",n,nn);
			if(!n||!nn)break;
		}
		cout<<res<<'\n';
	}
}