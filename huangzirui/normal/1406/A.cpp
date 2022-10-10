#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=110;
int i,j,k,n,m,T,a[maxn];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		for(i=0;i<=100;i++)a[i]=0;
		for(i=1;i<=n;i++)a[read()]++;
		for(i=0;i<=101;i++)if(a[i]<=1){ans=i;break;}
		for(i=ans;i<=101;i++)if(!a[i]){ans+=i;break;}
		cout<<ans<<endl;
	}
}