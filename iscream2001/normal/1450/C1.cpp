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
int vis[310][310];
char s[310][310];
char t[310][310];
char ans[310][310];
int now;
int a[310][310];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);now=n*n;
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
		}
		int x;
		x=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				t[i][j]=s[i][j];
				if((i+j)%3==0&&t[i][j]=='X'){
					t[i][j]='O';
					++x;
				}
			}
		}
		if(x<now){
			now=x;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j) ans[i][j]=t[i][j];
			}
		}
		x=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				t[i][j]=s[i][j];
				if((i+j)%3==1&&t[i][j]=='X'){
					t[i][j]='O';
					++x;
				}
			}
		}
		if(x<now){
			now=x;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j) ans[i][j]=t[i][j];
			}
		}
		x=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				t[i][j]=s[i][j];
				if((i+j)%3==2&&t[i][j]=='X'){
					t[i][j]='O';
					++x;
				}
			}
		}
		if(x<now){
			now=x;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j) ans[i][j]=t[i][j];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				putchar(ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}