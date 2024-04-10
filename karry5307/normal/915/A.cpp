#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,need,num,maxn;
int main()
{
    cin>>cnt>>need;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num;
        if(need%num==0)
        {
            maxn=max(maxn,num);
        }
    }
    cout<<(double)(need)/maxn;
}