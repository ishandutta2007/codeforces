#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int ans=0,res,now;
int a[N],b[N],c[10][10];
signed main(){
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++){
		res+=a[i]*b[i];
	}
	ans=res;
	for(int i=1;i<=n;i++){
		now=res;
		for(int j=1;;j++){
			if(i-j<=0||i+j>n)break;
			now-=a[i-j]*b[i-j];
			now-=a[i+j]*b[i+j];
			now+=a[i-j]*b[i+j];
			now+=a[i+j]*b[i-j];
			ans=max(ans,now);
		}
	}
	for(int i=1;i<=n;i++){
		now=res;
		for(int j=1;;j++){
			int l=i-j+1,r=i+j;
			if(l<=0||r>n)break;
			now-=a[l]*b[l];
			now-=a[r]*b[r];
			now+=a[l]*b[r];
			now+=a[r]*b[l];
			ans=max(ans,now);
		}
	}
	cout<<ans<<endl;
	return 0;
}