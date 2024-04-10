#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll w=a+2*b+3*c;
		if(a==1 && c==1 && !b){
			cout<<2<<endl;
		}else if(w&1)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}