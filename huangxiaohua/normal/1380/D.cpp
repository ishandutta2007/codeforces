#include <bits/stdc++.h>
using namespace std;
 
long long n,m,x,k,y,q[200500],qn,qmax,a[200500],b[200500],i,j,l=-1,r=-1,res;
 
int check(){
	if(k*y>=x&&qn>=k){res+=qn/k*x+qn%k*y;return 0;}
	if(k*y<x&&qmax<max(l,r)){res+=qn*y;return 0;}
	if(k*y<x&&qmax>max(l,r)&&qn>=k){res+=y*(qn-k)+x;return 0;}
	if(qmax>max(l,r)&&qn<k){return 1;}
	if(qmax<=max(l,r)&&qn<k){res+=qn*y;return 0;}
}
 
int main(){
	scanf("%d%d%d%d%d",&n,&m,&x,&k,&y);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<=n+1;i++){
		if(a[i]!=b[j]){qn++;q[qn]=a[i];qmax=max(qmax,q[qn]);continue;}
		if(a[i]==b[j]&&l==-1){l=b[j];j++;continue;}
		if(a[i]==b[j]&&r==-1){
			r=b[j];j++;
			if(qn>0){
				if(check()){puts("-1");return 0;}
			}
			l=r;r=-1;qn=0;qmax=0;
		}
	}
	if(j!=m+2){puts("-1");return 0;}
	printf("%lld\n",res);
}