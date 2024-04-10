#include<bits/stdc++.h>
#define For(i,a,A) for(int i=a,i##end=A;i<=i##end;i++)
#define Rof(i,a,A) for(int i=a,i##end=A;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=1e5+9;
const int B=16384;
const int inf=2e9+1;
int min(int x,int y){return x>y?y:x;}
int max(int x,int y){return x>y?x:y;}
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,k,ans=inf;
bitset<B>Bit[B*6],A;
map<int,int>id;int idx;
struct node{
	int v,a[6];
}t[N];
inline bool check(int l,int r){return l>=r||t[l].v+t[l+1].v>=ans;}
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,n){
		rep(j,m)t[i].a[j]=read();
		t[i].v=read();
	}
	sort(t+1,t+n+1,[&](node&x,node&y){return x.v<y.v;});
	t[n+1].v=ans;int lim=n/B;
	For(v,0,lim){
		int l=max(v*B,1),r=min((v+1)*B-1,n);
		if(check(l,r))break;
		while(idx)Bit[idx].reset(),idx--;idx=0;
		id.clear();
		For(i,l,r)rep(j,m){
			k=t[i].a[j];
			int nt=id[k];
			k=(nt?nt:(id[k]=++idx));
			Bit[k][i-l]=1;
		}
		rep(i,n){
			if(t[1].v+t[i].v>=ans)break;A.set();
			rep(j,m){
				k=id[t[i].a[j]];
				A&=(~Bit[k]);
				if(l+A._Find_first()>r)break;
			}
			int pos=l+A._Find_first();
			ans=min(ans,(pos<=r)?(t[i].v+t[pos].v):inf);
		}
	}
	if(ans>=inf)puts("-1");
	else cout<<ans<<endl;
	return 0;
}