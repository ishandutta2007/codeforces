#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int x,y;
		x=read();y=read();
		if(x*2>y)puts("-1 -1");
		else printf("%d %d\n",x,2*x);
	}
}