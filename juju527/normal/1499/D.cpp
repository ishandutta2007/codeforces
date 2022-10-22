#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e7+5,W=2e7;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxn];
int len,p[maxn];
int w[maxn];
void pre(){
	w[1]=0;
	for(int i=2;i<=W;i++){
		if(!bj[i])p[++len]=i,w[i]=1;
		for(int j=1;1ll*p[j]*i<=W&&j<=len;j++){
			bj[i*p[j]]=1;
			w[i*p[j]]=w[i];
			if(i%p[j]==0)break;
			w[i*p[j]]++;
		}
	}
	return ;
}
int main(){
	int T;
	T=read();
	pre();
	while(T--){
		int c,d,x;
		c=read();d=read();x=read();
		int b=sqrt(x);
		ll res=0;
		for(int i=1;i<=b;i++){
			if(x%i)continue;
			if((d+i)%c==0)res+=(1<<w[(d+i)/c]);
			if(i!=x/i&&(d+x/i)%c==0)res+=(1<<w[(d+x/i)/c]);
		}
		printf("%lld\n",res);
	}
    return 0;
}