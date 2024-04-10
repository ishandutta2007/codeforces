#include<bits/stdc++.h>
using namespace std;
int n,mmin,mmax,maxcnt,mincnt;
int main(){
	scanf("%d",&n);
	scanf("%d",&mmin);
	mmax=mmin;
	maxcnt=1;
	mincnt=1;
	for(int i=1;i<n;++i){
		int x;
		scanf("%d",&x);
		if(x>mmax){
			mmax=x;
			maxcnt=1;
		}else if(x==mmax){
			++maxcnt;
		}
		if(x<mmin){
			mmin=x;
			mincnt=1;
		}else if(x==mmin){
			++mincnt;
		}
	}
	printf("%d %lld",mmax-mmin,mmax==mmin?1ll*n*(n-1)/2:1ll*maxcnt*mincnt);
	return 0;
}