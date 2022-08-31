#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());
 
const int N = 1<<12|3, lim = 6;
map<int,int>Map[N];int n,p[N];
int qry(int x, int y){
	if(x>y)swap(x,y);
	if(Map[x].count(y))return Map[x][y];
	printf("? %d %d\n",x,y);fflush(stdout);
	int r;read(r);return Map[x][y]=r;
}
int main() {
	read(n);
	int a=R()%n+1,b=R()%n+1;
	while(1){
		a=R()%n+1,b=R()%n+1;
		while(a==b)a=R()%n+1,b=R()%n+1;
		int all=qry(a,b);
		int pa=0,pb=0;
		rep(tt,1,lim)if(all){
			int x=R()%n+1;while(x==a||x==b)x=R()%n+1;
			int A=qry(a,x),B=qry(b,x);
			rep(i,0,10)if((all>>i&1)&&(A>>i&1)!=(B>>i&1)){
				all^=1<<i;
				if(A>>i&1)pa|=1<<i;else pb|=1<<i;
			}
		}
		
		if(!all){
			p[a]=pa;p[b]=pb;break;
		}
	}
	
	static int id[N];int len=0;rep(i,1,n)if(i!=a&&i!=b)id[++len]=i;
	int pos=-1;if(p[a]==0)pos=a;if(p[b]==0)pos=b;
	rep(i,1,len)swap(id[i],id[R()%i+1]);
	rep(i,1,len)
	
		if(pos>=0){p[id[i]]=qry(id[i],pos);}
		else{
			p[id[i]]=(qry(id[i],a)&(~p[a]))|(qry(id[i],b)&(~p[b]));
			if(p[id[i]]==0)pos=id[i];
		}
	printf("! ");rep(i,1,n)printf("%d ",p[i]);fflush(stdout);
	return 0;
}