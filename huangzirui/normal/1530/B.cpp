#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,s[25][25];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--){
		cin>>n>>m;
		int len=n+n+m+m;len-=4;
		memset(s,0,sizeof(s));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i==1 || i==n || j==1 || j==m){
					if((!s[i-1][j-1])&&(!s[i-1][j])&&(!s[i-1][j+1])&&(!s[i][j-1]))s[i][j]=1;
				}cout<<s[i][j];
			}cout<<endl;
		}
	}
}