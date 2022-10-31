#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,T,mp[100500],nxt[20][100500],p[100500],a[100500],p2[200]={1};
vector<int> v[100500];

int main(){
	for(i=2;i<=100000;i++){
		if(p[i]){continue;}
		for(j=i;j<=100000;j+=i){v[j].push_back(i);p[j]=1;}
	}
	scanf("%d%d",&n,&T);
	for(i=0;i<=20;i++){nxt[i][n+1]=n+1;}
	for(i=1;i<=20;i++){p2[i]=p2[i-1]*2;}
	for(i=1;i<=100000;i++){mp[i]=n+1;}
	for(i=1;i<=n;i++){scanf("%d",&a[i]);nxt[0][i]=n+1;}
	for(i=n;i>=1;i--){
		for(auto j:v[a[i]]){if(nxt[0][i]>mp[j]){nxt[0][i]=mp[j];}mp[j]=i;}
	}
	for(i=n;i>=1;i--){nxt[0][i]=min(nxt[0][i],nxt[0][i+1]);}
	for(i=n;i>=1;i--){
		for(j=1;j<=19;j++){nxt[j][i]=nxt[j-1][nxt[j-1][i]];}
	}
	while(T--){
		int l,r,res=0;
		scanf("%d%d",&l,&r);
		while(1){
			if(nxt[0][l]>r){res++;break;}
			for(i=1;i<=19;i++){if(nxt[i][l]>r){l=nxt[i-1][l];res+=p2[i-1];break;}}
		}
		printf("%d\n",res);
	}
}