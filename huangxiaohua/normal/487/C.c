#include<stdio.h>
#include<math.h>

long long i,j,n;

long long ksm(long long a,long long p){
    long long res=1;
    while(p){
    if(p&1){res=res*a%n;}
        a=a*a%n;p>>=1;
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    if(n==1){puts("YES\n1");return 0;}
    if(n==4){puts("YES\n1\n3\n2\n4");return 0;}
    for(i=2;i*i<=n;i++){
        if(n%i==0){puts("NO");return 0;}
    }
    
    puts("YES\n1");
    for(i=2;i<n;i++){
        printf("%lld\n",i*ksm(i-1,n-2)%n);
    }
    printf("%d\n",n);
}