#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
int k[mn];
int num[mn*10];
int main()
{
    int n,i,j,a,b,la,lb;
    ll l=0x3f3f3f3f3f3f3f3f;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",k+i),num[k[i]]++;
    for(i=1;i<=10000000;i++){
        a=b=-1;
        for(j=i;j<=10000000;j+=i){
            if(num[j]>=1){
                if(a==-1)a=j;
                else if(b==-1)b=j;
            }
            if(num[j]>=2){
                if(a==-1)a=j;
                else if(b==-1)b=j;
            }
        }
        if(a==-1||b==-1)continue;
        if(1LL*a*b/i<l)l=1LL*a*b/i,la=a,lb=b;
    }
    a=b=-1;
    for(i=0;i<n;i++){
        if(k[i]==la&&a==-1)a=i;
        if(k[i]==lb&&a!=i&&b==-1)b=i;
    }
    if(a>b)swap(a,b);
    printf("%d %d",a+1,b+1);
}