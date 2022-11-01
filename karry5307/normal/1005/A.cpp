#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,num[1005],tot=-1,step[10001],last=0x7fffffff;
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num[i];
    }
    for(register int i=0;i<=cnt;i++)
    {
        if(num[i]<=last)
        {
            step[++tot]=num[i];
            last=num[i];
        }
        else
        {
            step[tot]=num[i];
        }
    }
    cout<<tot<<endl;
    for(register int i=0;i<tot;i++)
    {
        cout<<step[i]<<" ";
    }
}