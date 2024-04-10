#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,p[1005000],a[1005000],l,r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(p,0,m*4+50);
		memset(a,0,m*4+50);
		for(i=1;i<=n;i++){
			cin>>k;
			p[k]+=1;a[k]++;
		}
		for(i=1;i<=m;i++){
			p[i]+=p[i-1];
		}
		for(i=1;i<=m;i++){
			if(!a[i])continue;
			for(j=1;j*i<=m;j++){
				l=j*i;r=min(m,j*i+i-1);
				//printf("NMSL%d %d %d %d\n",i,j,l,r);
				if((p[r]-p[l-1])<=0)continue;
				if(!a[j]){
					cout<<"No\n";goto aaa;
				}
			}
		}
		cout<<"Yes\n";
		aaa:;
	}
	
}