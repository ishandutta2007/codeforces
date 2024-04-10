#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=5010;
int i,j,k,n,m,T,s1[maxn][maxn],s2[maxn][maxn],a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++){
			s1[i][n+1]=0;
			for(j=n;j>=i;j--)s1[i][j]=s1[i][j+1]+(a[i]>a[j]);
			for(j=1;j<=i;j++)s2[i][j]=s2[i][j-1]+(a[i]>a[j]);
		}
		ll ans=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
//				cerr<<i<<' '<<j<<' '<<s1[i][j+1]<<' '<<s2[j][i-1]<<endl;
				ans+=s1[i][j+1]*s2[j][i-1];
			}
		cout<<ans<<endl;
	}
	return 0;
}