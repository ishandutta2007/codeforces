#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
ll rdll(){
    ll a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

const int N=100005;

int n,t;

int main(){
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
        if(n==1)printf("0\n");
        else if(n==3)printf("1\n");
        else if(n==7)printf("1\n");
        else if(n==15)printf("5\n");
        else if(n==31)printf("1\n");
        else if(n==63)printf("21\n");
        else if(n==127)printf("1\n");
        else if(n==255)printf("85\n");
        else if(n==511)printf("73\n");
        else if(n==1023)printf("341\n");
        else if(n==2047)printf("89\n");
        else if(n==4095)printf("1365\n");
        else if(n==8191)printf("1\n");
        else if(n==16383)printf("5461\n");
        else if(n==32767)printf("4681\n");
        else if(n==65535)printf("21845\n");
        else if(n==131071)printf("1\n");
        else if(n==262143)printf("87381\n");
        else if(n==524287)printf("1\n");
        else if(n==1048575)printf("349525\n");
        else if(n==2097151)printf("299593\n");
        else if(n==4194303)printf("1398101\n");
        else if(n==8388607)printf("178481\n");
        else if(n==16777215)printf("5592405\n");
        else if(n==33554431)printf("1082401\n");
	    else{
	        int a=1;
	        while(a<n)a=a<<1|1;
	        printf("%d\n",a);
	    }
	}
	return 0;
}