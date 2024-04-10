// Hydro submission #62677b849f31360077e12b78@1650948997174
#include<bits/stdc++.h>
using namespace std;
int s[7],t;
int main()
{
    int n,i;
    cin>>n;
    while(n)
    {
        s[++s[0]]=n%2;
        n/=2;
    }
    swap(s[3],s[4]);
    swap(s[1],s[5]);
    for(i=6;i>0;i--)
    t=t*2+s[i];
    printf("%d\n",t);
    return 0;
}