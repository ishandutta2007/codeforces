#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll need,first,mon,tot;
int main()
{
    cin>>first>>mon>>need;
    if(need^(need|1))
    {
        tot=need/2*(1+need)*first;
    }
    else
    {
        tot=(1+need)/2*need*first;
    }
    if(mon>=tot)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<tot-mon<<endl;
    }
}