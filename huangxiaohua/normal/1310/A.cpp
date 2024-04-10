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
 
#include <bits/stdc++.h>
using namespace std;
 
struct s{
	int a;
	int b;
}sb[200500];
 
inline int read() {
    int f = 0, fu = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')fu = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        f = (f << 3) + (f << 1) + c - 48;
        c = getchar();
    }
    return f * fu;
}
 
int n,i,qr,j;
long long res,qsum;
priority_queue<int> q;
struct cmp{bool operator()(s a,s b){if(a.a!=b.a){return a.a<b.a;}return a.b<b.b;}};
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sb[i].a=read();
	}
	for(i=1;i<=n;i++){
		sb[i].b=read();
	}
	sort(sb+1,sb+n+1,cmp());
	
	for(i=1;i<=n+2;i++){
		if(q.empty()){qsum=sb[i].b;qr=sb[i].a;q.push(sb[i].b);continue;}
		while(!q.empty()&&sb[i].a!=qr){
			qsum-=q.top();qr++;q.pop();
			res+=qsum;
		}
		if(sb[i].a==qr||q.empty()){qsum+=sb[i].b;qr=sb[i].a;q.push(sb[i].b);continue;}
	}
	printf("%lld",res);
}