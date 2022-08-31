#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	int i,n,d,t,st;
	scanf("%d%d",&n,&d);
	vector<int>a(n,0);
	scanf("%d",&a[0]);
	st=0;
	for(i=1;i<n;i++){
	   scanf("%d",&a[i]);
	   if(a[i]<=a[i-1]){
	     t=1+(int)((a[i-1]-a[i])/d);
	     a[i]=a[i]+d*t;
	     st+=t;
	   }
	}
	printf("%d\n",st);      
	return 0;
}