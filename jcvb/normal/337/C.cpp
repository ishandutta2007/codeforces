#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#define mo 1000000009
using namespace std;
int n,m,k;
int po(int a,int b){
    int ans=1;
    while(b){
             if(b&1)ans=1ll*ans*a%mo;
             a=1ll*a*a%mo;
             b>>=1;
    }
    return ans;
}
int main()
{
   // freopen("exam.in","r",stdin);
   // freopen("exam.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int num=m-(n-n/k);
    if(num<=0){
               printf("%d\n",m);
               return 0;
    }
    int ans=1ll*(po(2,num+1)-2)*k%mo;
    ans+=(1ll*(m-1ll*num*k))%mo;
    printf("%d\n",(ans%mo+mo)%mo);
    return 0;
}