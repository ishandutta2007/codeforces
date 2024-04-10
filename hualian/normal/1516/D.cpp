#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],s[N];
int last[N];
int nt[N][30];
int main(){
	memset(last,0x3f,sizeof last);
	int n=read(),q=read();
	for(int i=1;i<=2*n;i++)for(int j=0;j<=20;j++)nt[i][j]=n+1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--){
		int now=a[i],ans=1e8;
		for(int j=2;j*j<=now;j++){
			if(now%j==0){
				while(now%j==0)now/=j;
				ans=min(ans,last[j]);
				last[j]=i;
			}
		}if(now>1)ans=min(ans,last[now]),last[now]=i;
		nt[i][0]=min(nt[i+1][0],ans);
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++)
		nt[i][j]=nt[nt[i][j-1]][j-1];
	}
	while(q--){
		int l=read(),r=read(),res=0;
		for(int i=20;i>=0;i--){
			if(nt[l][i]>r)continue;
			res+=1<<i,l=nt[l][i];
		}
		cout<<res+1<<endl;
	}
	return 0;
}