// Hydro submission #6295ff45b0c5e75beb145ab6@1653997382078
#include<cstdio>
#define db double
#define gc getchar
#define pc putchar
#define U unsigned
#define ll long long
#define ld long double
#define ull unsigned long long
#define Tp template<typename _T>
#define Me(a,b) memset(a,b,sizeof(a))
Tp _T mabs(_T a){ return a>0?a:-a; }
Tp _T mmax(_T a,_T b){ return a>b?a:b; }
Tp _T mmin(_T a,_T b){ return a<b?a:b; }
Tp void mswap(_T &a,_T &b){ _T tmp=a; a=b; b=tmp; return; }
Tp void print(_T x){ if(x<0) pc('-'),x=-x; if(x>9) print(x/10); pc((x%10)+48); return; }
#define EPS (1e-7)
#define INF (0x7fffffff)
#define LL_INF (0x7fffffffffffffff)
#define maxn 59
#define maxm 100039
#define MOD
#define Type int
#ifndef ONLINE_JUDGE
//#define debug
#endif
using namespace std;
Type read(){
	char c=gc(); Type s=0; int flag=0;
	while((c<'0'||c>'9')&&c!='-') c=gc(); if(c=='-') c=gc(),flag=1;
	while('0'<=c&&c<='9'){ s=(s<<1)+(s<<3)+(c^48); c=gc(); }
	if(flag) return -s; return s;
}
int n,m,nn,mm,cnt,tmpx; char p[maxn][maxn],s[maxn][maxn];
struct JTZ{ int x,y; }ans[maxm],tmp[maxm];
#define mp(x,y) (JTZ){x,y}
void rotate(int x,int y){
	cnt++; ans[cnt].x=x; ans[cnt].y=y;
	if(s[x][y]=='L'){ s[x][y]=s[x][y+1]='U'; s[x+1][y]=s[x+1][y+1]='D'; }
	else{ s[x][y]=s[x+1][y]='L'; s[x][y+1]=s[x+1][y+1]='R'; } return;
}
void dfs(int x,int y){
	if(s[x][y]=='U'){
		if(s[x][y+1]=='U') rotate(x,y);
		else dfs(x+1,y+1),rotate(x,y+1),rotate(x,y);
	} return;
}
void work(){
	int i,j; cnt=0; for(i=1;i<=n;i++) scanf("%s",p[i]+1);
	if(m&1){
		for(i=1;i<=n;i++) for(j=1;j<=m;j++){
			switch(p[i][j]){
				case 'L': s[j][i]='U'; break;
				case 'R': s[j][i]='D'; break;
				case 'U': s[j][i]='L'; break;
				case 'D': s[j][i]='R'; break;
			}
		}
	} else for(i=1;i<=n;i++) for(j=1;j<=m;j++) s[i][j]=p[i][j];
	for(i=1;i<=nn;i++) for(j=1;j<=mm;j++) if(s[i][j]=='U') dfs(i,j);
	if(m&1) for(i=1;i<=cnt;i++) mswap(ans[i].x,ans[i].y); return;
}
int main(){
	//freopen("ex_floor1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(); m=read(); int i; nn=n; mm=m; if(m&1) mswap(nn,mm);
	work(); tmpx=cnt; for(i=1;i<=cnt;i++) tmp[i].x=ans[i].x,tmp[i].y=ans[i].y;
	work(); print(cnt+tmpx),pc('\n'); for(i=1;i<=tmpx;i++) print(tmp[i].x),pc(' '),print(tmp[i].y),pc('\n');
	for(i=cnt;i>=1;i--) print(ans[i].x),pc(' '),print(ans[i].y),pc('\n'); return 0;
}