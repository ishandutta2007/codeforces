#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll num,cnt,times[100001],kind;
int main()
{
    cin>>cnt>>num;
    for(register int i=0;i<cnt;i++)
    {
        cin>>times[i];
        times[i]+=num;
        if(times[i]<=5)
        {
            kind++;
        }
    }
    cout<<kind/3;
}