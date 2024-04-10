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
		ll n,m,k;
		cin>>n>>k;
		ll w=(n/2)/(k+1);
		cout<<w<<' '<<w*k<<' '<<n-w*(k+1)<<endl;
}