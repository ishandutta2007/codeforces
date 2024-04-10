#include<bits/stdc++.h>//
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[10050],vis[10050],l,r,cnt,vis2[10050];

int r1[105],r2[105];

void chk(int l,int r){
	int i,j,k;
	for(i=1;i<=n*m;i++){
		if(vis[i]||a[i]>r||a[i]<l){continue;}
		if(vis2[a[i]]){continue;}
		for(j=i-1;j>=1;j--){
			if(vis[j]){break;}
			if(a[i]==a[j]){
				cnt++;
				r2[a[i]]=i;
				r1[a[i]]=j;
				vis[i]=vis[j]=1;
				vis2[a[i]]=1;
				break;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i+=(m-1)){
		l=i;r=l+m-2;
		chk(l,r);
		memset(vis,0,sizeof(vis));
	}
	for(i=1;i<=n;i++){
		printf("%d %d\n",r1[i],r2[i]);
	}
}