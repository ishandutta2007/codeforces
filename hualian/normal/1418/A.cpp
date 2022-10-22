#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3010;
int t,n,k;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
signed main(){
	t=read();
	while(t--){
		int x=read(),y=read();
		k=read();
		int ans=y*k+k+x-2;
		ans=(ans-1)/(x-1);
		cout<<ans+k<<endl;
	}
	return 0;
}