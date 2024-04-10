#include<bits/stdc++.h>
using namespace std;
int ff[]={1,1,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        scanf("%d",&a);
        int f=0,ans=0,p=__builtin_popcount(a);
        bool flag=false;
        while(a)
        {
            if(a%2==0) flag=true;
            ans+=(1<<f);
            f++;
            a/=2;
        }
        if(flag) printf("%d\n",ans);
        else printf("%d\n",ff[p]);
    }
}