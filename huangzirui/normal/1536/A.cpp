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
		cin>>n;int a[110],s=0;
		for(i=1;i<=n;i++)a[i]=read(),s|=(a[i]<0);
		if(!s){
		cout<<"YES"<<endl;
		cout<<200<<endl;
		for(i=0;i<=199;i++)cout<<i<<' ';cout<<endl;
		}else cout<<"NO"<<endl;
	}
}