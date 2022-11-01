#include<bits/stdc++.h>
#define fi first
#define se second
#define ULL unsigned long long
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,s[505],ans[505][505];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	for(int i=1;i<=n;i++)ans[i][i]=s[i];
	for(int i=1;i<=n;i++){
		int x=i,y=i;
		for(int j=0;j<s[i]-1;j++){
			if(y>1&&!ans[x][y-1])y--;
			else x++;
			ans[x][y]=s[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)printf("%d ",ans[i][j]);
		puts("");
	}
}