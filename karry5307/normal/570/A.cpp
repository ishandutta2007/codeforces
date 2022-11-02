#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll elect[201],vote[201],cnt,ccnt,maxn;
int main()
{
    cin>>cnt>>ccnt;
    for(register int i=0;i<ccnt;i++)
    {
        maxn=0;
        for(register int j=0;j<cnt;j++)
        {
            cin>>elect[j];
            if(elect[j]>elect[maxn])
            {
                maxn=j;
            }
        }
        vote[maxn]++;
    }
    maxn=0;
    for(register int i=0;i<cnt;i++)
    {
        if(vote[i]>vote[maxn])
        {
            maxn=i;
        }
    }
    cout<<maxn+1<<endl;
}