#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll num,tot;
int main()
{
    cin>>num;
    while(num)
    {
        if(num%2)
        {
            tot++;
        }
        num/=2;
    }
    cout<<tot;
}