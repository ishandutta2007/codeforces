// Hydro submission #6319b98b533abd4b31871ed0@1662630284085
#include<bits/stdc++.h>
using namespace std;
#define maxn 3009
int t;
int a[maxn],n,f[maxn][maxn];
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();a[i]++;
			for(int j=0;j<=n+2;j++)f[i][j]=1e9;
			if(i>1)f[1][i]=0;
		}
		for(int i=1;i<=n;i++){
			if(i>1){
				int cost=0;
				for(int j=i-1;j>=0;j--){
					if(j+a[j]>i){
						f[i][j+a[j]]=min(f[i][j+a[j]],f[j][i]+cost);cost++;
					}
				}
				for(int j=i+2;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][j-1]);
				}
			}
		}
		cout<<f[n][n+1]<<endl;
	}
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}