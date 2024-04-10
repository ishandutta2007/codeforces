#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=10010;
int i,j,k,n,m,T,a[maxn];
bool dp[maxn][2510];
bool check(int s){
	for(i=1;i<=2500;i++)dp[0][i]=(i<=s);
	for(i=1;i<=n;i++){
		for(j=1;j<=s;j++){
			dp[i][j]=false;
			if(j-a[i]>=1)dp[i][j]|=dp[i-1][j-a[i]];
			if(j+a[i]<=s)dp[i][j]|=dp[i-1][j+a[i]];
		}
	}
	for(i=1;i<=s;i++)if(dp[n][i])return true;
	return false;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read(); 
		int L=0,R=2500;
		while(L<=R){
			int Mid=L+R>>1;
			if(check(Mid))R=Mid-1;
			else L=Mid+1;
		}printf("%d\n",R);
	}
	return 0;
}