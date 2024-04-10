#include<iostream>
#include<algorithm>
#include<cstdio>
#include<deque>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,a) for(int i=a;i<(int)m;++i)
using namespace std;
int n,x;
int seq[505];
int main(){
	scanf("%d%d",&n,&x);
	REP(i,n) scanf("%d",&seq[i]);
	sort(seq,seq+n);
	int med=(n-1)/2;
	if(seq[med]==x) printf("%d\n",0);
	else if(seq[med]>x){
		int res=0;
		while((n-1)/2-res>=0 && seq[(n-1)/2-res]>x){
			++res;
			++n;
		}
		printf("%d\n",res);
	}else{
		int res=0;
		int prevn=n;
		while((n-1)/2<prevn && seq[(n-1)/2]<x){
			++res;
			++n;
		}
		printf("%d\n",res);
	}
	return 0;
}