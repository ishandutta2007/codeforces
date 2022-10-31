// Hydro submission #62d791049ef728749e1dfb97@1658294532519
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m;
    cin>>t;
    while(t--)
    {
        cin>>m;
        printf("%d\n",m-int(pow(10,int(log10(m)))));
    }
    return 0;
}