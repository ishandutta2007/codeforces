#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
const int N=3e5+7;
int n,x1,x2;
pii c[N];
bool f=0;
int p[N],cnt;
void out(int a,int b,int c,int d){
	if(f)swap(a,c),swap(b,d);
	printf("Yes\n%d %d\n",b-a+1,d-c+1);
	cnt=0;
	REP(i,a,b)p[++cnt]=::c[i].Y;
	sort(p+1,p+1+cnt);
	REP(i,1,cnt)printf("%d ",p[i]);puts("");
	cnt=0;
	REP(i,c,d)p[++cnt]=::c[i].Y;
	sort(p+1,p+1+cnt);
	REP(i,1,cnt)printf("%d ",p[i]);puts("");
}
int rr=0;
int num[N],siz,ss;
pii qa[N];
#define l(x) ((x-1)*siz+1)
#define r(x) (x==ss?n:x*siz)
#define bel(x) ((x-1)/siz+1)
inline int ask(int p){
//	dbg("ppp%d\n",p);
	if(!p)return 0;
	if(p<=siz){
		REP(i,1,p){//dbg("iii %d %d\n",i,num[i]);
		if(num[i]<=p)return i;
		}
		return 0;
	}
	int be=bel(p)-1;
	REP(i,1,be){
		
		int t=upper_bound(qa+l(i),qa+r(i)+1,make_pair(p,0x3f3f3f3f))-qa-1;//dbg("kuai %d %d -> %d %d %d\n",i,l(i),r(i),t,qa[l(i)]);	
		if(t>=l(i))return qa[t].Y;
	}
	++be;
	REP(i,l(be),p)if(num[i]<=p)return i;
	return 0;
}
void check(int x){
	int t1=ceil(1.0*x1/x);
	int p=lower_bound(c+1,c+1+n,make_pair(t1,0))-c;
//	dbg("pp%d\n",p);
	if(n-p+1<x)return;
	if(p+x<=rr)out(p,p+x-1,rr,n),exit(0);
	int t=ask(p-1);
	if(t)out(p,p+x-1,t,num[t]),exit(0);
}
int main(){
	n=read(),x1=read(),x2=read();
	if(x1>x2)f=1,swap(x1,x2);
	REP(i,1,n)c[i]=make_pair(read(),i);
	sort(c+1,c+1+n);
	DEC(i,n,1){
		int x=ceil(1.0*x2/(n-i+1));
		if(c[i].X>=x){
			rr=i;break;
		}
	}
	REP(i,1,n)num[i]=(x2-1)/c[i].X+i,qa[i]=make_pair(num[i],i);
	siz=sqrt(n/log2(n));ss=bel(n);
	REP(i,1,ss)sort(qa+l(i),qa+r(i)+1);
//	dbg("rr %d\n",rr);
	if(!rr)return puts("No"),0;
	REP(i,1,n)check(i);
	puts("No");
	return 0;
}