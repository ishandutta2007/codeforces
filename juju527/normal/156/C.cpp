#include <bits/stdc++.h>
using namespace std;
const int maxl=105,mod=1e9+7;
char s[maxl];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int L=100;
int f[maxl][25*maxl];
void pre(){
	f[0][0]=1;
	for(int i=0;i<=L;i++){
		for(int v=0;v<=25*i;v++){
			if(!f[i][v])continue;
			for(int c=0;c<26;c++){
				f[i+1][v+c]+=f[i][v];
				if(f[i+1][v+c]>=mod)f[i+1][v+c]-=mod;
			}
		}
	}
	return ;
}
int main(){
//    freopen("CF156C.in","r",stdin);
//    freopen("CF156C.out","w",stdout);
    pre();
	int T;
	T=read();
	while(T--){
		scanf("%s",s);
		int l=strlen(s),w=0;
		for(int i=0;i<l;i++)w+=s[i]-'a';
		printf("%d\n",(f[l][w]-1+mod)%mod);
	}
    return 0;
}