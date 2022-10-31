#include<bits/stdc++.h>
using namespace std;
 
struct sb{
	int a;
	int b;
}a[6666];
int n,i,res[1005000][2],rn,j,b[6666];
 
int cmp1(sb a,sb b){
	if(a.a!=b.a){return a.a<b.a;}
	return a.b<b.b;
}
 
int cmp2(sb a,sb b){
	return a.b<b.b;
}
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		b[i]=a[i].a;
		a[i].b=i;
	}
	for(j=n;j>=2;j--){
		sort(a+1,a+n+1,cmp2);
		sort(a+1,a+j,cmp1);
		for(i=1;i<=j-1;i++){
			if(a[i].a>=a[j].a&&b[a[i].b]>b[j]){
				rn++;res[rn][0]=a[i].b;res[rn][1]=j;
			}
		}
	}
	
	
	printf("%d\n",rn);
	for(i=1;i<=rn;i++){
		printf("%d %d\n",res[i][0],res[i][1]);
	}
}