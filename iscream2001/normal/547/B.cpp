#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=2e5+10;

void init(){
	
}
int n;
int a[N],t[N];

int tp[2];
int q[2][N];

void sol(int l,int r){
	if(l>r) return;
	if(l==r){
		t[1]=max(t[1],a[l]);
		return;
	}
	int mid=(l+r)>>1;
	
	tp[0]=tp[1]=0;q[0][0]=l-1;q[1][0]=r+1;
	for(int i=l;i<=mid;++i){
		while(tp[0]>0&&a[q[0][tp[0]]]>=a[i]) --tp[0];
		q[0][++tp[0]]=i;
	}
	
	for(int i=r;i>=mid;--i){
		while(tp[1]>0&&a[q[1][tp[1]]]>=a[i]) --tp[1];
		q[1][++tp[1]]=i;
	}
	
	for(int i=tp[0],j=tp[1];;){
		t[q[1][j-1]-1-q[0][i-1]]=max(t[q[1][j-1]-1-q[0][i-1]],min(a[q[1][j]],a[q[0][i]]));
		if(i==1&&j==1) break;
		if(i==1&&j>1){--j;continue;}
		if(j==1&&i>1){--i;continue;}
		if(a[q[1][j-1]]<a[q[0][i-1]]){
			--i;
		}
		else{
			--j;
		}
	}
	
	sol(l,mid-1);
	sol(mid+1,r);
	return;
}

void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sol(1,n);
	for(int i=n-1;i>=1;--i){
		t[i]=max(t[i],t[i+1]);
	}
	for(int i=1;i<=n;++i){
		printf("%d ",t[i]);
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}