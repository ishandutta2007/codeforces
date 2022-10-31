#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
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
 
int n,t,i,j,tmp,tmp2,tmp3,tmp4,tmp5,tmp6,res,b[200500],qn,c,d,k;
 
struct aa{
	int a;
	int b;
}a[200500],q[200500];
 
struct cmp{bool operator()(aa c,aa d){if(k==0){if(c.a!=d.a){return c.a<d.a;}return c.b<d.b;}return c.b<d.b;}};
 
int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d",&n);tmp=res=tmp2=tmp3=0;
		memset(b,1,4*n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].a);
			a[i].b=i;
		}k=0;
		a[0].a=a[0].b=-1;
		sort(a+1,a+n+1,cmp());
		
		for(i=1;i<=n;i++){
			if(a[i].a!=a[i+1].a||a[i].a!=a[i-1].a){b[i]=0;}
		}
		
		for(i=1;i<=n;i++){
			if(b[i]==0){
			tmp4=-1;
			tmp2=a[i].a;
			tmp3=tmp6=-1;
			for(j=i;j<=n;j++){
				if(a[j].a==tmp2){tmp++;}
				else{tmp3=a[j].b;tmp6=a[j].a;break;}
			}res=max(tmp,res);tmp=0;tmp5=1145141919;
			if(a[i].b>tmp3){b[i]=1;}
			
				for(j=i;j<=n;j++){
					if(a[j].a==tmp2&&a[j].b>tmp3){continue;}
					if(a[j].a>tmp5){break;}
					if(a[j].b<tmp4&&tmp5==1145141919){tmp5=a[j].a;continue;}
					if(a[j].b<tmp4){continue;}
					if(a[j].a!=a[j+1].a){b[j]=1;}tmp++;tmp4=a[j].b;
				}
				res=max(tmp,res);tmp=0;
			
			qn=c=d=0;

			if(a[i].a==a[i+1].a){
				for(j=i;j<=n&&a[j].a<=tmp6;j++){
				qn++;q[qn].a=a[j].a;q[qn].b=a[j].b;
				if(a[j].a==tmp6){d++;}
				}k=1;
			}
			
			if(qn<=2){continue;}
			sort(q+1,q+qn+1,cmp());

			for(j=1;j<=qn;j++){
				if(q[j].a!=tmp6){c++;}else{d--;}
				res=max(res,c+d);
			}

		}}
		printf("%d\n",n-res);
	}
}