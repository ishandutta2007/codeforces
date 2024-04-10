#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num[201],parity,kind;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num[i];
        num[i]%2?parity^=1:cnt;
    }
    for(register int i=0;i<cnt;i++)
    {
        !(num[i]%2^parity)?kind++:cnt;
    }
    cout<<kind;
}