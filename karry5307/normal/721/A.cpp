#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,tot=-1,step[10001];
char num[1005];
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num[i];
    }
    for(register int i=0;i<cnt;i++)
    {
        if(num[i]=='B')
        {
            if(i==0||num[i-1]=='W')
            {
                step[++tot]=1;
            }
            else
            {
                step[tot]++;
            }
        }
    }
    cout<<tot+1<<endl;
    for(register int i=0;i<tot+1;i++)
    {
        cout<<step[i]<<" ";
    }
}