#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T;ll s[maxn];
string S;
int main(){
	cin>>n>>m;
	cin>>S;
	for(i=1;i<=n;i++)s[i]=s[i-1]+S[i-1]-'a'+1;
	for(i=1;i<=m;i++){
		int l,r;
		l=read();r=read();
		printf("%lld\n",s[r]-s[l-1]);
	}
	return 0;
}