#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
using namespace std;
 
int i,t,n,m,k,q[100500],son[100500],qn,j,link[100500],x,y,p[100500],h[100500],rt[100500],sb[100500],bad;
vector<int> v[100500];
 
namespace IO {
const int MAXSIZE = 1 << 22;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline int rd() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}
}
 
void chk(int n){
	int i,tmp;
	for(i=0;i<v[n].size();i++){
		tmp=v[n][i];
		if(link[tmp]==0){link[tmp]=n;qn++;q[qn]=tmp;son[n]++;}
	}
}
 
int main(){
	t=IO::rd();while(t--){
	n=IO::rd();m=IO::rd();
	memset(link,0,n*4+50);
	memset(sb,0,n*4+50);
	qn=1;
	
	for(i=1;i<=n;i++){
		p[i]=IO::rd();
		rt[i]=p[i];
		v[i].clear();
	}
	for(i=1;i<=n;i++){
		h[i]=IO::rd();
	}
	
	for(i=1;i<=n-1;i++){
		x=IO::rd();y=IO::rd();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	q[1]=1;link[1]=-1;
	for(i=1;qn!=n;i++){
		chk(q[i]);
	}
	
	qn=0;
	for(i=1;i<=n;i++){
		if(son[i]==0){qn++;q[qn]=i;}
	}
	
	for(i=1;i<=qn;i++){
		sb[q[i]]=1145141919;
	}
	
	link[1]=0;
	for(i=1;i<=n;i++){
		son[link[q[i]]]--;
		if(son[link[q[i]]]==0){qn++;q[qn]=link[q[i]];}
		if(abs(h[q[i]])>rt[q[i]]){putchar('N');putchar('O');memset(son,0,n*4+50);goto aaa;}
		if((rt[q[i]]-h[q[i]])%2==1){putchar('N');putchar('O');memset(son,0,n*4+50);goto aaa;}
		bad=(rt[q[i]]-h[q[i]])/2;
		if(bad>sb[q[i]]+p[q[i]]){putchar('N');putchar('O');memset(son,0,n*4+50);goto aaa;}
		
		rt[link[q[i]]]+=rt[q[i]];
		sb[link[q[i]]]+=bad;
	}
 
	putchar('Y');putchar('E');putchar('S');
	aaa:putchar('\n');continue;
}}