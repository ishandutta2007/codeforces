#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,need,num;
int main()
{
    cin>>cnt>>need;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        need-=(86400-num);
        if(need<=0)
        {
            cout<<i+1;
            return 0;
        }
    }
}