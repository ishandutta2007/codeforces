#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<math.h>
#define LL unsigned long long int
using namespace std;
int i,j,sb[200055],t,n,r,l,jb[200055];
 
int main(){
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);r=0;l=1;
		for(j=1;j<=n;j++){
			scanf("%d",&sb[j]);
		}
		sort(sb+1,sb+1+n);
		for(j=1;j<=n;j++){
			jb[j]=jb[j-1]+1;
			if(jb[j]==sb[j]){
				r++;jb[j]=0;
			}
		}
		printf("%d\n",r);
	}
	return 0;
}