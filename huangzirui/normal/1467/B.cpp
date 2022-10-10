#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=300010;
int i,j,k,n,m,T,a[maxn],vis[maxn];
int check(int x){
	if(x<=1 || x>=n)return 0;
	return (a[x]>a[x-1] && a[x]>a[x+1])||(a[x]<a[x-1] && a[x]<a[x+1]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read(),vis[i]=0;
		int ans=0;
		for(i=1;i<=n;i++){
			if(i!=1 && i!=n){
				if(a[i]<a[i+1] && a[i]<a[i-1])vis[i]=1,ans++;
				if(a[i]>a[i+1] && a[i]>a[i-1])vis[i]=1,ans++;
			}
		}
		int w=0,S=ans;
		for(i=1;i<=n;i++){
			int x=ans-vis[i]-vis[i-1]-vis[i+1];
			int tmp=a[i-1];
			swap(tmp,a[i]);
			S=min(S,x+check(i-1)+check(i)+check(i+1));
			swap(tmp,a[i]);
			tmp=a[i+1];
			swap(tmp,a[i]);
			S=min(S,x+check(i-1)+check(i)+check(i+1));
			swap(tmp,a[i]);
		}
		for(i=1;i<=n;i++)vis[i]=a[i]=0;
		printf("%d\n",S);
	}
}