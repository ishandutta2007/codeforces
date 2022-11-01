#include<bits/stdc++.h>
using namespace std;
typedef int ll;
queue<ll>mon;
ll game[1005];
ll cnt,ccnt,num,pos,maxn;
int main()
{
    cin>>cnt>>ccnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>game[i];
    }
    for(register int i=0;i<ccnt;i++)
    {
        cin>>num;
        mon.push(num);
    }
    while(pos!=cnt&&!mon.empty())
    {
        if(mon.front()>=game[pos])
        {
            mon.pop(),maxn++;
        }
        pos++;
    }
    cout<<maxn;
}