// Hydro submission #625d4b7281ef68d42bcbf627@1650281331175
// Problem: CF1000F One Occurrence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1000F
// Memory Limit: 750 MB
// Time Limit: 3000 ms

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
#include <algorithm>
#include <math.h>
#include <stdio.h>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T power(T base,T index,T mod){return((index<=1)?(index?base:1):(power(base*base%mod,index>>1,mod)*power(base,index&1,mod)))%mod;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(!b)return y=0,x=1,a;T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}
template<const uint Sqrt=1500>
struct Block
{
	uint A[Sqrt*Sqrt],B[Sqrt];
	Block()
	{
		for(uint i=0;i<Sqrt*Sqrt;i++)A[i]=0;
		for(uint i=0;i<Sqrt;i++)B[i]=0;
	}
	voi insert(uint v){A[v]++,B[v/Sqrt]++;}
	voi erase(uint v){A[v]--,B[v/Sqrt]--;}
	uint findmax()
	{
		for(uint i=Sqrt-1;~i;i--)if(B[i])
			for(uint j=Sqrt-1;~j;j--)if(A[i*Sqrt+j])return i*Sqrt+j;
		return-1;
	}
};
Block<750>B;
uint Siz;
struct ques{uint l,r,t,ans;};
bol cmp1(const ques&a,const ques&b){return(a.l/Siz==b.l/Siz)?(((a.l/Siz)&1)?b.r<a.r:(a.r<b.r)):(a.l<b.l);}
bol cmp2(const ques&a,const ques&b){return a.t<b.t;}
uint A[500005];
uint Time[500005];
ques Q[500005];
uint l,r;
voi insert(uint m)
{
	if(Time[A[m]]==1)B.erase(A[m]);
	if(++Time[A[m]]==1)B.insert(A[m]);
}
voi erase(uint m)
{
	if(Time[A[m]]==1)B.erase(A[m]);
	if(--Time[A[m]]==1)B.insert(A[m]);
}
int main()
{
	B.insert(0);
	uint n,m;
	scanf("%u",&n),Siz=sqrt(n);
	for(uint i=0;i<n;i++)scanf("%u",A+i);
	scanf("%u",&m);
	for(uint i=0;i<m;i++)scanf("%u%u",&Q[i].l,&Q[i].r),Q[i].l--,Q[i].t=i;
	std::sort(Q,Q+m,cmp1),l=r=0;
	for(uint i=0;i<m;i++)
	{
		ques&qs=Q[i];
		while(l>qs.l)insert(l-1),l--;
		while(r<qs.r)insert(r),r++;
		while(l<qs.l)erase(l),l++;
		while(r>qs.r)erase(r-1),r--;
		qs.ans=B.findmax();
	}
	std::sort(Q,Q+m,cmp2);
	for(uint i=0;i<m;i++)printf("%u\n",Q[i].ans);
	return 0;
}