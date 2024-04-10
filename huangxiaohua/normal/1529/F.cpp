#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,f[605][605],a[605],u[605],x,y,w,v;

int min(int x,int y){return x<y?x:y;}

int main(){
	memset(f,63,sizeof(f));
	scanf("%d%d",&n,&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&w);
		f[x][y]=min(f[x][y],w);
	}
	for(i=0;i<n;i++){
		memset(u,0,sizeof(u));
		memset(a,63,sizeof(a));
		for(j=0;j<n;j++){
			a[j]=f[i][j];
		}
		t=n;
		while(t--){
			v=601;
			for(j=0;j<n;j++){
				if(!u[j]&&a[j]<a[v]){v=j;}
			}
			a[(v+1)%n]=min(a[(v+1)%n],a[v]+1);
			u[v]=1;
			for(j=0;j<n;j++){
				a[(j+a[v])%n]=min(a[(j+a[v])%n],a[v]+f[v][j]);
			}
		}
		for(j=0;j<n;j++){
			printf("%d ",(j==i)?0:a[j]);
		}puts("");
	}
}