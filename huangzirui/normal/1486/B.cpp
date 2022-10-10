#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=1010;
struct node{
	int X,Y;
}d[maxn];
int i,j,k,n,m,T,a[maxn],b[maxn];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read(),b[i]=read();
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		if(n&1)cout<<1<<endl;
		else 
		cout<<(1ll*a[n/2]-a[n/2+1]-1)*(b[n/2]-b[n/2+1]-1)<<endl;
	}
}