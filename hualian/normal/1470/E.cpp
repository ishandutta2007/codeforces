#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=3e4+9;
const int C=5;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,c;
int a[N];
struct node{
	int l,r,cnt;
	bool operator<(const node&x)const{return a[r]<a[x.r];}
};
struct Deque{
	int l,r,nl,nr;
	node _a[2*N*C];
	node *a=&_a[N*C];
	int _b[2*N*C];
	int *b=&_b[N*C];
	pair<int,int>G[N];
	void check(int x){
		sort(a+l-nl,a+l);l-=nl;
		sort(a+r+1,a+r+nr+1);r+=nr;
		nl=nr=0;G[x]=make_pair(l,r);
	}
	void init(){
		l=r=nl=nr=0;
		a[l]=node{n,n,1};
		check(n);
	}
	void pushl(node x){a[l-(++nl)]=x;}
	void pushr(node x){a[r+(++nr)]=x;}
	void calc(){
		b[l-1]=0;
		For(i,l,r)b[i]=b[i-1]+a[i].cnt;
	}
}q[C];
int binom(int n,int m){
	if(n==m&&m==0)return 1;
	if(n<m)return 0;
	int res=1;
	For(i,n-m+1,n)res*=i;
	rep(i,m)res/=i;return res;
}
int calc(int n,int c){//C(n-1,0~c)
	if(n<=1)return 1;
	int res=0;
	For(i,0,c)res+=binom(n-1,i);
	return res;
}
int lim;
void init(){
	node res;
	For(i,0,c){
		q[i].init(); 
		Rof(j,n-1,1){// 
			For(k,j+1,min(j+i,n)){// 
				res=node{j,k,calc(n-k,i-(k-j))};
				if(a[k]<a[j])q[i].pushl(res);
				else q[i].pushr(res);
			}q[i].check(j);
		}q[i].calc();
	}lim=calc(n,c);
}
node find(int pos,int val,int rk){
	int l=q[val].G[pos].first;
	int r=q[val].G[pos].second;
	int res=-1e9,be=l-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(q[val].b[mid]-q[val].b[be]>=rk){
			res=mid;r=mid-1;
		}else l=mid+1;
	}
	node ans=q[val].a[res];
	ans.cnt=q[val].b[res-1]-q[val].b[be];
	return ans;
}
vector<pair<int,int> >ans;
void ask(){
	int x=read(),y=read();
	if(y>lim){puts("-1");return;}
	ans.clear();
	int pos=1,val=c;
	while(val&&pos<=n){
		node res=find(pos,val,y);
		ans.push_back(make_pair(res.l,res.r));
		y-=res.cnt;val-=res.r-res.l;
		pos=res.r+1;
	}
	for(auto i:ans)if(i.first<=x&&x<=i.second){
		printf("%lld\n",a[i.first+i.second-x]);
		return;
	}printf("%lld\n",a[x]);
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();while(T--){
		n=read(),c=read();int q=read();
		rep(i,n)a[i]=read();
		init();while(q--)ask();
	}
	return 0;
}

///////////////////