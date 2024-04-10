#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC optimize(5)
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
#define LL long long int
#define M 1000000007
struct shit{
	int a[2];
}s[1000500],num[500500];
int cmp(shit c,shit b){
	return c.a[0]<b.a[0];
}
int ans[500500],sb[500500],m,n,i,j,tmp=0,tmp2[500500];
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=n*2;i+=2){
		scanf("%d%d",&s[i].a[0],&s[i].a[1]);
		s[i+1].a[0]=s[i].a[1];
		s[i+1].a[1]=s[i].a[0];
	}
	for(i=1;i<=m;i++){
		num[i].a[1]=i;
		scanf("%d",&num[i].a[0]);
	}
	sort(s+1,s+n*2+1,cmp);
	sort(num+1,num+m+1,cmp);
	for(i=1;i<=n*2;i++){
		//printf("a%d %d\nb%d %d\n",s[i].a[0],s[i].a[1],num[i].a[0],num[i].a[1]);
		if(s[i].a[0]>tmp){tmp=s[i].a[0];sb[tmp]=i;}
	}
	for(i=1;i<=m;i++){
		tmp=1;tmp2[0]=0;//printf("c%d\n",sb[i]);
		for(j=sb[num[i].a[1]];s[j].a[0]==num[i].a[1];j++){
			tmp2[0]++;tmp2[tmp2[0]]=ans[s[j].a[1]];
		}
		sort(tmp2+1,tmp2+tmp2[0]+1);
		for(j=1;j<=tmp2[0];j++){
			if(tmp==tmp2[j]){tmp++;}
			if(tmp<tmp2[j]){break;}
		}
		if(tmp!=num[i].a[0]){puts("-1");return 0;}
		else{ans[num[i].a[1]]=num[i].a[0];
		}
	}
	for(i=1;i<=m;i++){
		printf("%d ",num[i].a[1]);
	}
}