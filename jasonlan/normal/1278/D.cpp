#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=501000;
int n;
int fa[maxn],bel[maxn<<1],R[maxn],cnt;
struct note{
	int op,pos,no;
	bool operator <(note b)const{
		return pos<b.pos;
	}
}q[maxn<<1];
set <int> s;
set <int>::iterator it;
inline int read(){
	int res=0;
	char ch=getchar(),ch2=ch;
	while(!isdigit(ch))ch2=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch2=='-'?-res:res;
}
int getfa(int x){
	return x==fa[x]?x:(fa[x]=getfa(fa[x]));
}
bool merge(int x,int y){
	x=getfa(bel[x]);y=getfa(bel[y]);
	if(x==y)return false;
	fa[y]=x;
	return true;
}
bool check(){
	int tnt=0;
	for(register int i=1;i<=cnt;++i)
		if(q[i].op){
			for(it=s.begin();it!=s.end();++it){
				if(*it>R[bel[q[i].pos]])break;
				if(++tnt==n)return false;
				if(!merge(R[bel[q[i].pos]],*it))return false;
			}
			s.insert(R[bel[q[i].pos]]);
		}
		else
			s.erase(s.find(q[i].pos));
	return tnt==n-1;
}
int main(){
	n=read();
	for(register int i=1,l;i<=n;++i){
		fa[i]=i;
		l=read();R[i]=read();
		q[++cnt].op=1;q[cnt].pos=l;q[cnt].no=i;
		q[++cnt].op=0;q[cnt].pos=R[i];q[cnt].no=i;
		bel[l]=bel[R[i]]=i;
	}
	sort(q+1,q+1+cnt);
	puts(check()?"YES":"NO"); 
	return 0;
}