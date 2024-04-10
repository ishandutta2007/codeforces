#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T;
ll a[maxn],s[maxn],Max[maxn][610];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]+a[i];
		for(i=1;i<=n;i++)for(j=1;j<=600;j++)Max[i][j]=-1;
		int ans=1;
		Max[n][1]=a[n];
		for(i=n-1;i>=1;i--){
			Max[i][1]=max(Max[i+1][1],a[i]);
			for(j=2;j<=600;j++){
				if(i+j>n)break;
				ll sum=s[i+j-1]-s[i-1];
				Max[i][j]=Max[i+1][j];
				if(sum<Max[i+j][j-1])Max[i][j]=max(Max[i][j],sum);
				if(Max[i][j]!=-1)ans=max(ans,j);
//				cout<<i<<' '<<j<<' '<<Max[i][j]<<' '<<Max[i+j][j-1]<<' '<<sum<<endl;
			}
		}//cout<<"ANS="<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}