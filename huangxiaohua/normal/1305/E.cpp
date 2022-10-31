#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int n,i,mx[5050],m,a,b;

void print(int x)
{
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

int main(){
	
	for(i=1;i<=5001;i++){
		mx[i]=mx[i-1]+(i-1)/2;
	}
	scanf("%d%d",&n,&m);
	if(m>mx[n]){puts("-1");return 0;}
	for(i=n;i>=1;i--){
		if(mx[i]<=m){a=i,b=m-mx[i];break;}
	}
	for(i=1;i<=n;i++){
		if(i<=a){print(i);putchar(' ');continue;}
		if(i==a+1){print(i*2-1-2*b);putchar(' ');continue;}
		print(10001+10002*i);putchar(' ');
	}

}