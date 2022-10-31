#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105][105];
struct sb{
	int it,x,y,w;
}s[10050];


int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=t;i++){
		scanf("%d",&k);
		s[i].it=k;
		if(k==1){
			scanf("%d",&s[i].x);
		}
		if(k==2){
			scanf("%d",&s[i].y);
		}
		if(k==3){
			scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].w);
		}
	}
	for(i=t;i>=1;i--){
		if(s[i].it==3){
			a[s[i].x][s[i].y]=s[i].w;continue;
		}
		if(s[i].it==1){
			k=a[s[i].x][m];
			for(j=m;j>=2;j--){
				a[s[i].x][j]=a[s[i].x][j-1];
			}
			a[s[i].x][1]=k;
		}
		else{
			k=a[n][s[i].y];
			for(j=n;j>=2;j--){
				a[j][s[i].y]=a[j-1][s[i].y];
			}
			a[1][s[i].y]=k;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
}