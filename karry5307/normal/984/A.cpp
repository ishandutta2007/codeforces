#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num,op=1;
deque<ll>l;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        l.push_back(num);
    }
    sort(l.begin(),l.end());
    while(l.size()!=1)
    {
        if(op)
        {
            l.pop_back();
        }
        else
        {
            l.pop_front();
        }
        op^=1;
    }
    cout<<l.front();
}