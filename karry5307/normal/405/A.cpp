//code
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num;
priority_queue<ll,vector<ll>,greater<ll> >q;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        q.push(num);
    }
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
}