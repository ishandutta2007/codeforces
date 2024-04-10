#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],s[N];
double ans;
signed main(){
	int T=read();
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)
			a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i]; 
		ans=-1e18;
		for(int i=n-1;i>=1;i--)
			ans=max(ans,1.0*s[i]/i+1.0*(s[n]-s[i])/(n-i));
		printf("%.8lf\n",ans);
	}
	return 0;
}