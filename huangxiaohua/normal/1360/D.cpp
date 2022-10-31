#include<bits/stdc++.h>
#include<math.h>
using namespace std;
 
int i,j,t,a,b,c,num;
int main(){
    scanf("%d",&t);for(i=1;i<=t;i++){scanf("%d%d",&a,&b);num=a;c=sqrt(a);c=min(c,b);
		for(j=1;j<=c;j++){
			if(a%j==0&&a/j<=b){num=min(num,j);}
			if(a%j==0&&a/j>b){num=min(num,a/j);}
		}
		printf("%d\n",num);
    }
    return 0;
}