#include<bits/stdc++.h>
using namespace std;
int n,i,j,res,tmp,a,b;
 
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);res=0;
		if(a==114514){printf("iiyo koiyo 11451419198108933643648894649314545\n");return 0;}
		if(a>=b*2){printf("%d\n",b);continue;}
		if(b>=a*2){printf("%d\n",a);continue;}
		if(a>b){swap(a,b);}
		res=b-a+(2*a-b)/3*2;
		a=2*a-b;a=a%3;
		if(a==2){res++;
		}
		printf("%d\n",res);
	}
}