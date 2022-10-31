#include<bits/stdc++.h>
using namespace std;
int i,n,k1,k2;
double h,c,t,k,t1,t2;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&h,&c,&t);
		if(t>=h){puts("1");continue;}
		if(t<=(h+c)/2){puts("2");continue;}
		k=(h-t)/(2*t-c-h);
		k1=k;k2=k1+1;
		t1=k1*(c+h)+h;t1/=(k1*2+1);
		t2=k2*(c+h)+h;t2/=(k2*2+1);
		if(fabs(t2-t)>=fabs(t1-t)){printf("%d\n",2*k1+1);}
		else{printf("%d\n",2*k2+1);}
		}
	
	return 0;
}