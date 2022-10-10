#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=300010;
int i,j,k,n,m,T,n1,n2,n3;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n1>>n2>>n3;
	ll s1=1e18,s2=1e18,s3=1e18,w=0,x1=0,x2=0,x3=0;
	for(i=1;i<=n1;i++){
		ll x=read();
		s1=min(s1,x);
		x1+=x;
		w+=x;
	}
	for(i=1;i<=n2;i++){
		ll x=read();
		s2=min(s2,x);
		x2+=x;
		w+=x;
	}
	for(i=1;i<=n3;i++){
		ll x=read();
		s3=min(s3,x);
		x3+=x;
		w+=x;
	}
	cout<<max(w-2*(s1+s2+s3-max(max(s1,s2),s3)),w-2*min(min(x1,x2),x3))<<endl;
}