#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
const int p=998244353;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int iv[N];
int n,mx;
	int son[N*30][2],sz[N*30],idx=1;
	void insert(int x){
		int now=1,nt;sz[now]++;
		for(int i=1<<29;i;i>>=1){
			nt=(x&i)?1:0;
			now=(son[now][nt]?son[now][nt]:son[now][nt]=++idx);
			sz[now]++;
		}
	}
	int solve(int a,int b,int dep){
		if(1ll*a*b==0){return (iv[sz[a]+sz[b]]);}
		if(a==b){
			if(dep==0)return iv[sz[a]];
			int ls=son[a][0],rs=son[a][1];
			if(mx&dep)return solve(ls,rs,dep>>1);
			int A=solve(ls,ls,dep>>1),B=solve(rs,rs,dep>>1);
			return A+B-1;
			return (solve(ls,ls,dep>>1)+solve(rs,rs,dep>>1)-1+p)%p;
		}else{
			if(dep==0)return iv[sz[a]+sz[b]];
			int ls1=son[a][0],rs1=son[a][1];
			int ls2=son[b][0],rs2=son[b][1];
			if(mx&dep)return solve(ls1,rs2,dep>>1)*solve(rs1,ls2,dep>>1)%p;
			else{
				int res=(solve(ls1,ls2,dep>>1)+solve(rs1,rs2,dep>>1)-1+p)%p;
				(res+=(iv[sz[ls1]]-1)*(iv[sz[rs1]]-1))%=p;
				(res+=(iv[sz[ls2]]-1)*(iv[sz[rs2]]-1))%=p;
				return res;
			}
		}
	}
long long ans;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),mx=read();
	iv[0]=1;rep(i,n)iv[i]=iv[i-1]*2%p;
	rep(i,n)insert(read());
	ans=solve(1,1,1<<29);
	cout<<(ans-1)%p<<endl;
	return 0;
}