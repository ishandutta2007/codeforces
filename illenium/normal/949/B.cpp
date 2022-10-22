#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

int main()  
{  
    int p;  
    LL n,m,a;  
    scanf("%lld%d",&n,&p);  
    while(p--)  
    {  
        scanf("%lld",&a);  
        if(a%2==1)  
        {  
            printf("%lld\n",a/2+1);  
            continue;  
        }  
        m=n;  
        while(a%2==0)  
        {  
            a=m-a/2;  
            m=a;  
        }  
        printf("%lld\n",n-a+(a+1)/2);  
    }  
}