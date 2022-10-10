#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

int i,j,k,n,m,T;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		int a[110],b[110];
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		bool B=0;
		for(i=1;i<=n;i++)if(a[i]+b[n-i+1]>m)B=1;
		if(B)puts("No");else puts("Yes");
	}
}