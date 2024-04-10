#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m;
char s[N];
int son[N*10][4],idx=1;
struct matrix{
	int a[4][4];
	matrix(){memset(a,0x3f,sizeof a);}
	matrix operator*(const matrix&x)const{
		matrix b;
		For(i,0,3)For(j,0,3)For(k,0,3)
			chmn(b.a[i][j],a[i][k]+x.a[k][j]);
		return b;
	}
}B;
struct tree{
	void insert(int l,int r){
		int x=1,i=l;
		while(i<=r){
			int to=s[i]-'A';
			if(son[x][to])x=son[x][to];
			else son[x][to]=++idx,x=idx;
			i++;
		}return;
	}
	void dfs(int x,int dep,int head){
		For(i,0,3)
			if(!son[x][i])chmn(B.a[head][i],dep);
			else dfs(son[x][i],dep+1,head);
		return;
	}
}T;
matrix inv(matrix x,int base){
	matrix res=x;
	while(base){
		if(base&1)res=res*x;
		x=x*x;
		base>>=1;
	}return res;
}
bool check(int mid){
	matrix A=inv(B,mid-1);
	For(i,0,3)For(j,0,3)if(A.a[i][j]<n)return false;
	return true;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();scanf("%s",s+1);m=strlen(s+1);
	rep(i,m)T.insert(i,min(i+10,m));
	For(i,0,3)T.dfs(son[1][i],1,i);
	int l=1,r=1e18;
	while(l<=r){
		int mid=(l+r)>>1;
		if(!check(mid))l=mid+1;
		else r=mid-1;
	}cout<<l<<endl;
	return 0;
}