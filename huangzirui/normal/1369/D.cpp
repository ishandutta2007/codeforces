#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=2000010,mod=1e9+7;
int i,j,k,n,m;
ll f[maxn][2];
int main(){
	int T;
	cin>>T;
	for(i=3;i<maxn;i++){
		f[i][0]=(max(f[i-2][0],f[i-2][1])*2+max(f[i-1][0],f[i-1][1]))%mod;
		f[i][1]=(f[i-2][0]*2+f[i-1][0]+4)%mod;
	}
	while(T--){
		n=read();
		printf("%lld\n",max(f[n][0],f[n][1]));
	}
	return 0;
}