#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=998244353;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int fc[2*maxn],iv[2*maxn];
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int binom(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fc[n]*iv[m]%mod*iv[n-m]%mod;
}
int main(){
	int n;
	n=read();
	int p=0,q=0,u=0,w=1;
	bool tag=0,tag0=1,tag1=1;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[0]!='?'&&s[1]!='?'){if(s=="BB")p+=2;else if(s!="WW")p++,u++;}
		else{
			if(s[0]=='?'&&s[1]=='?')q+=2,w=add(w+w),u++;
			else{
				if(s=="?B"||s=="B?")p++,q++,u++;
				else if(s=="?W"||s=="W?")q++,u++;
			}
		}
		if(s=="BB"||s=="WW")tag=1;
		if(s[0]=='W'||s[1]=='B')tag0=0;
		if(s[0]=='B'||s[1]=='W')tag1=0;
	}
	fc[0]=1;for(int i=1;i<=2*n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[2*n]=power(fc[2*n],mod-2);for(int i=2*n-1;i>=0;i--)iv[i]=1ll*iv[i+1]*(i+1)%mod;
	int res=binom(q,n-p);
	if(!tag){
		if(u==n)res=sub(res-w);
		res+=tag0+tag1;
	}
	printf("%d\n",res);
	return 0;
}