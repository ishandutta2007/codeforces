#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,it;
__int128 f[66],jc[66];
ll g[66],sb;
int fa[66];
bool vis[66];

int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}

void work(int it,int l,int r){
	cout<<it+r<<' ';r--;
	ll rnk=(sb-1)/f[max(0,n-it-r-1)];
	sb-=rnk*f[max(0,n-it-r-1)];
	rnk++;
	int i,j,k;
	for(i=1;i<=51;i++)fa[i]=i;
	memset(vis,0,sizeof(vis));
	
	for(i=l;i<=r;i++){
		for(j=l;j<=r;j++){
			if(find(i+1)==find(j)||vis[j])continue;
			if(rnk>jc[max(0,r-i-1)]){
				rnk-=jc[max(0,r-i-1)];
			}
			else{
				fa[find(j)]=fa[find(i+1)];
				vis[j]=1;
				cout<<it+j<<' ';
				break;
			}
			
		}
	}
}

int main(){
	jc[0]=1;
	for(i=1;i<=50;i++){
		jc[i]=jc[i-1]*i;
		if(jc[i]>2e18){
			jc[i]=2e18;
		}
	}
	f[0]=g[0]=1;
	for(i=1;i<=50;i++){
		f[i]=f[i-1];
		for(j=2;j<=i;j++){
			f[i]+=jc[j-2]*f[i-j];
		}
		if(f[i]>2e18){
			f[i]=2e18;
		}
		g[i]=f[i];
	}
	cin>>t;
	while(t--){
		cin>>n>>sb;
		if(sb>f[n]){
			cout<<"-1\n";continue;
		}
		it=0;
		while(it!=n){
			for(i=1;;i++){
				if(i==1){
					if(f[n-it-1]>=sb){
						cout<<++it<<' ';break;
					}
					else{
						sb-=f[n-it-1];
					}
					continue;
				}
				if(jc[i-2]*f[n-it-i]<sb){
					sb-=jc[i-2]*f[n-it-i];
					continue;
				}
				work(it,1,i);
				it+=i;
				break;
			}
		}
		cout<<'\n';
	}
}