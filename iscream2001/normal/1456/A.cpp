#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int INF=2e9;
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
int n,p,k;
char s[N];
int f[N];
int main(){
	int T,x,y;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",s+1);
		scanf("%d%d",&x,&y);
		int ans=INF,res=0;
		for(int i=n;i>=p;i--){
			if(i+k<=n) f[i]=f[i+k];else f[i]=0;
			if(s[i]=='0') f[i]+=x;
			ans=min(ans,f[i]+(i-p)*y);
		}
		printf("%d\n",ans);
	}
	return 0;
}