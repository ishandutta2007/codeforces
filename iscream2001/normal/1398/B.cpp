#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1000+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	return ch;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
char s[N];
int q[N];int tp=0;
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		tp=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		int m=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'){
				if(m>0){
					q[++tp]=m;m=0;
				}
			}
			else{
				++m;
			}
		}
		if(m>0) q[++tp]=m;
		sort(q+1,q+1+tp);
		int ans=0;
		for(int i=tp;i>=1;i-=2){
			ans+=q[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}