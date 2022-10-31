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
typedef unsigned long long ll;
 
namespace IO {
const int MAXSIZE = 1 << 25;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)
inline ll rd() {
  ll x = 0;
  char c = gc();
  while (!isdigit(c)) {
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x;
}
}
 
struct sjb{
	ll jian;
	ll qz;
	ll bs;
	ll sum;
	friend bool operator < (sjb a, sjb b)     
	{         
		return a.jian<b.jian;     
	}
}s[100500],ss;
 
int i,t,n,m,k,q[100500],son[100500],qn,j,link[100500],sb[100500],a,b,c,sol,tmp,tmp2;
long long jb,qz[100500],bs[100500],res;
vector<int> v[100500],v2[100500];
 
priority_queue<sjb> stk;
 
void chk(int n){
	int i,tmp;
	for(i=0;i<v[n].size();i++){
		tmp=v[n][i];
		if(link[tmp]==0){link[tmp]=n;qn++;q[qn]=tmp;son[n]++;qz[tmp]=v2[n][i];}
	}
}
 
int main(){
	t=IO::rd();
	while(t--){
		while(!stk.empty()){
			stk.pop();
		}
		n=IO::rd();jb=IO::rd();
		res=sol=s[1].sum=s[1].qz=s[1].bs=s[1].jian=0;
		memset(link,0,n*4+50);
		memset(bs,0,n*4+50);
		
		for(i=1;i<=n;i++){
			v[i].clear();v2[i].clear();s[i].bs=bs[i]=0;
		}
		
		for(i=1;i<=n-1;i++){
			//s[i].num=s[i].beishu=0;
			a=IO::rd();
			b=IO::rd();
			c=IO::rd();
			v[a].push_back(b);v[b].push_back(a);
			v2[a].push_back(c);v2[b].push_back(c);
		}
		link[1]=-1;q[1]=1;qn=1;
		for(i=1;i<=n;i++){
			chk(q[i]);
		}
		link[1]=qn=0;
		for(i=1;i<=n;i++){
			if(son[i]==0){qn++;q[qn]=i;bs[i]=1;}
			//printf("%d %d %d\n",link[i],i,qz[i]);
		}
		//printf("%d\n",qn);
		for(i=1;i<n;i++){
			son[link[q[i]]]--;
			if(son[link[q[i]]]==0){qn++;q[qn]=link[q[i]];}
			bs[link[q[i]]]+=bs[q[i]];
			s[q[i]].qz=qz[q[i]];
			s[q[i]].bs=bs[q[i]];
			s[q[i]].sum=s[q[i]].qz*s[q[i]].bs;
			s[q[i]].jian=s[q[i]].sum-s[q[i]].qz/2*s[q[i]].bs;
			res+=s[q[i]].qz*s[q[i]].bs;
			stk.push(s[q[i]]);
		}
		//for(i=1;i<=n;i++){printf("%lld %lld %lld %lld %lld\n",i,s[i].qz,s[i].bs,s[i].sum,s[i].jian);}
		
		while(res>jb){
			res-=stk.top().jian;
			//printf("%lld %lld %lld\n",stk.top().qz,stk.top().bs,stk.top().jian);
			//printf("%lld\n",res);
			ss.bs=stk.top().bs;
			ss.qz=stk.top().qz/2;
			ss.sum=ss.bs*ss.qz;
			ss.jian=ss.sum-ss.qz/2*ss.bs;
			
			stk.pop();
			stk.push(ss);
			sol++;
		}
		printf("%d\n",sol);
	}
}