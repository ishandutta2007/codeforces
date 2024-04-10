#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N][N],len;

signed main(){
	int t=read();
	while(t--){
		int n=read();
		int cnt=0;
		if(n==2){puts("-1");continue;}
		for(int i=1;i<=n;i++){
			int j=2;
			if(i%2)j=1;
			for(;j<=n;j+=2){
				a[i][j]=++cnt;
			}
		}
		for(int i=1;i<=n;i++){
			int j=1;
			if(i%2)j=2;
			for(;j<=n;j+=2){
				a[i][j]=++cnt;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";puts("");
		}
		
	}
	return 0;
}