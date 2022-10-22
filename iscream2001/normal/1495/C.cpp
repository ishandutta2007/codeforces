#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
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
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int n,m; 
char s[510][510];
void upd(int x,int y){
	if(n==1){
		s[1][x]=s[1][y]='X';
		return;
	}
	if(s[2][x]!='X'&&s[2][y]!='X'){
		s[1][x]=s[1][y]='X';
		return;
	}
	s[2][x]=s[2][y]='X';
	return;
}
void MAIN(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
    	scanf("%s",s[i]+1);
	}
	if(m%3==0){
		for(int i=2;i<=m;i+=3){
			for(int j=1;j<=n;++j) {
				s[j][i]='X';
			}
			if(i>=4){
				upd(i-2,i-1);
			}
		}
	}
	else{
		for(int i=1;i<=m;i+=3){
			for(int j=1;j<=n;++j) s[j][i]='X';
			if(i>=4){
				upd(i-2,i-1);
			}
		}
		
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			putchar(s[i][j]);
		}
		puts("");
	}
    return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}