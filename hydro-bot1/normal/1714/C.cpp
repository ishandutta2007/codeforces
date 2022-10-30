// Hydro submission #62fb46bbe42c71bad9ebe69b@1660634811522
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,a,i;
    cin>>t;
    while(t--)
    {
        cin>>n;s=0,a=9,i=1;
        while(n)
        {
            if(n>=a)
            {
                n-=a;
                s+=a*i;
                i*=10;
            }
            a--;
        }
        printf("%d\n",s);
    }
    return 0;
}