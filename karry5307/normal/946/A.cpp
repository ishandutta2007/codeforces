#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,a,b,num;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        if(num>=0)
        {
            a+=num;
        }
        else
        {
            b+=num;
        }
    }
    cout<<a-b;
}