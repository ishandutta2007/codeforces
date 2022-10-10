#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn];
ll ans=0;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		n=read();ans=0;ll Sum=0,Sum2=1ull<<60;
		int Min1=2e9,Min2=2e9,t1=n,t2=n;
		for(i=1;i<=n;i++){
			a[i]=read();
			Sum+=a[i];
			if(i&1)Min1=min(Min1,a[i]),t1--;
			else Min2=min(Min2,a[i]),t2--;
			ans=1ll*t1*Min1+1ll*t2*Min2+Sum;
			Sum2=min(Sum2,ans);
		}cout<<Sum2<<endl;
	}
}