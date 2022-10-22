#pragma optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
namespace io{
	const int Sz=1<<13;
	char ibuf[Sz],*ed=ibuf+Sz,*ips=ed-1;
	int getchar(){
		if(++ips==ed)ed=ibuf+fread(ips=ibuf,1,Sz,stdin);
		if(ips<ed)return*ips;else return EOF;
	}
}
#define getchar io::getchar
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f^=1;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return f?x:-x;
}
const int N=5e5+5;
const int B=707;
int n,a[N],q;
struct Q{
	int l,r,id;
	int bl,br;
	inline void get(int i){
		l=read()-1,r=read(),id=i;
		bl=l/B,br=r/B;
	}
	inline bool operator<(const Q&x)const{
		return bl!=x.bl?bl<x.bl:(bl&1?br<x.br:br>x.br);
	}
}qq[N];
int hav[B+1];
bitset<N>is;
int tms[N],sum;
inline void add(int x,int v){
	if(tms[x]==1)sum--,is.reset(x),hav[x/B]--;
	tms[x]+=v;
	if(tms[x]==1)sum++,is.set(x),hav[x/B]++;
}
inline int get(){
	if(!sum)return 0;
	int i=0;while(!hav[i])++i;
	int j=i*B;while(!is[j])++j;
	return j;
}
int ans[N];
int main(){
	n=read();
	for(int i=0;i<n;++i)a[i]=read();
	q=read();
	for(int i=0;i<q;++i)qq[i].get(i);
	sort(qq,qq+q);
	int l=qq[0].l,r=l;
	for(int i=0;i<q;++i){
		int nl=qq[i].l,nr=qq[i].r;
		while(r<nr)add(a[r++],1);
		while(l>nl)add(a[--l],1);
		while(r>nr)add(a[--r],-1);
		while(l<nl)add(a[l++],-1);
		ans[qq[i].id]=get();
	}
	for(int i=0;i<q;++i)printf("%d\n",ans[i]);
	return 0;
}