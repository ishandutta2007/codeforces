#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=151000,maxb=2110000;
int n,m,k;
ll anscnt,ans[maxn];
int pos[maxn],cnt[maxb],xora[maxn];
struct cnq{
	int x,y,d;
}note[maxn];
bool cmp(cnq a,cnq b){
	if(pos[a.x]!=pos[b.x])return pos[a.x]<pos[b.x];
	return a.y<b.y;
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void makeblock(){
	int t=sqrt(n);
	for(register int i=1;i<=n;++i)
		pos[i]=(i-1)/t+1;
}
void add(int p){
	anscnt+=(ll)cnt[k^p];
	++cnt[p];
}
void del(int p){
	--cnt[p];
	anscnt-=(ll)cnt[k^p];
}
int main(){
	n=read()+1;m=read();k=read();
	makeblock();
	for(register int i=2;i<=n;++i)
		xora[i]=xora[i-1]^read();
	for(register int i=1;i<=m;++i){
		note[i].x=read();note[i].y=read()+1;note[i].d=i;
	}
	sort(note+1,note+1+m,cmp);
	for(register int i=1,l=note[i].x,r=l-1,t=0;i<=m;++i){
		while(l>note[i].x)
			--l,add(xora[l]);
		while(l<note[i].x)
			del(xora[l]),++l;
		while(r<note[i].y)
			++r,add(xora[r]);
		while(r>note[i].y)
			del(xora[r]),--r;
		ans[note[i].d]=anscnt;
	}
	for(register int i=1;i<=m;++i)
		printf("%lld\n",ans[i]);
	return 0;
}