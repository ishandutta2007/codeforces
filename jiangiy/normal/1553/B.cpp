#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
char s[505],t[1005];
bool a[505][1005],b[505][1005];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)a[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)b[i][j]=0;
		bool ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i+j-1>n||s[i+j-1]!=t[j])break;
				a[i+j-1][j]=1;
			}
			for(int j=m;j;j--){
				if(i+m-j>n||s[i+m-j]!=t[j])break;
				b[i+m-j][j]=1;
			}
			for(int j=1;j<=m;j++)ans|=a[i][j]&&b[i][j];
		}
		puts(ans?"YES":"NO");
	}
}