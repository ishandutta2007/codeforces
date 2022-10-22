#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,K;
char s[N];
int main(){
	int T;scanf("%d",&T);
	bool f1,f0;
	while(T--){
		scanf("%d%d",&n,&K);
		scanf("%s",s+1);
		for(int i=1;i<=K;++i){
			f0=0;f1=0;
			for(int j=i;j<=n;j+=K){
				if(s[j]=='0') f0=1;
				if(s[j]=='1') f1=1;
			}
			if(f0==1&&f1==1) break;
			for(int j=i;j<=n;j+=K){
				if(f1) s[j]='1';
				if(f0) s[j]='0';
			}
		}
		if(f0==1&&f1==1){
			puts("NO");
			continue;
		}
		int A=0,B=0;
		for(int i=1;i<=K;++i){
			if(s[i]=='1') ++A;
			if(s[i]=='0') ++B;
		}
		if(A>(K/2)||B>(K/2)){
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}