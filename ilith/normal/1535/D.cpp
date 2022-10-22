#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define mid (l+r>>1)
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=1200010;
int n,k,sum[N],cnt,q;
int st[N],hd,tl,id[N<<1];
char opt[N];
char s[N];
int L[N],R[N];
void pup(int k){
	if(opt[k]=='0')sum[k]=sum[k<<1];
	if(opt[k]=='1')sum[k]=sum[k<<1|1];
	if(opt[k]=='?')sum[k]=sum[k<<1]+sum[k<<1|1];
}
void getid(){
	st[hd=tl=1]=1;
	while(hd>=tl){
		int x=st[tl++];
		if(x>(n<<2))continue;
		opt[x]=s[id[x]=--cnt];
		st[++hd]=x*2+1;
		st[++hd]=x*2;
	}
}
void build(int k,int l,int r){
	if(r==l)return void(sum[k]=1);
	build(k<<1|1,mid+1,r),build(k<<1,l,mid);
	L[id[k]]=l,R[id[k]]=r,pup(k);
}
void upd(int k,int l,int r,int x,int y,char ch){
	if(l>y||r<x)return;
	if(l>=x&&r<=y)return opt[k]=ch,pup(k);
	upd(k<<1,l,mid,x,y,ch),upd(k<<1|1,mid+1,r,x,y,ch);
	pup(k);
}
int pos;
char C;
signed main(){
	read(k),scanf("%s",s+1);
	cnt=n=(1<<k),getid(),build(1,1,n);
	read(q);
	while(q--){
		scanf("%d %c",&pos,&C);
		upd(1,1,n,L[pos],R[pos],C);
		write(sum[1],'\n');
	} 
	return 0;
}