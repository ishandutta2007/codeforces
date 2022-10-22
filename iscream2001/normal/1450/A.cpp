#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int INF=1e9;
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
int n;
char s[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i){
			if(s[i]=='b') putchar(s[i]);
		}	
		for(int i=1;i<=n;++i){
			if(s[i]!='b') putchar(s[i]);
		}
		puts("");
	}
	return 0;
}