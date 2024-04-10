#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,ans[10010],a[200010];
int main(){
	cin>>T;
	while(T--){
		memset(ans,0,sizeof(ans));
		cin>>n;
		int Ans=0;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				ans[abs(a[i]-a[j])]=1;
		for(i=1;i<=10000;i++)Ans+=ans[i];
		cout<<Ans<<endl;
	}
	return 0;
}