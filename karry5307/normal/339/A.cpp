#include<bits/stdc++.h>
using namespace std;
typedef int ll;
priority_queue<ll,vector<ll>,greater<ll> >q;
ll num;
int main()
{
    while(scanf("%d",&num)==1)
    {
        q.push(num);
    }
    cout<<q.top();
    q.pop();
    cout<<setiosflags(ios::showpos);
    while(!q.empty())
    {
        cout<<q.top();
        q.pop();
    }
}