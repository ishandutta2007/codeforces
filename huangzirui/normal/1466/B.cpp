#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010; 
int i,j,k,n,m,T,a[maxn],s[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		for(i=1;i<=n;i++)s[a[i]=read()]++; 
		for(i=1;i<=2*n+1;i++)
			s[i]+=(s[i-1]>1),ans+=s[i]?1:0;
		for(i=1;i<=2*n+1;i++)s[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}