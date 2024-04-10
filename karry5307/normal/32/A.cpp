#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll num[100001],diff,cnt,kind;
int main()
{
    cin>>cnt>>diff;
    for(register int i=0;i<cnt;i++)
    {
        cin>>num[i];
    }
    for(register int i=0;i<cnt;i++)
    {
        for(register int j=0;j<cnt;j++)
        {
            if(abs(num[i]-num[j])<=diff&&i!=j)
            {
                kind++;
            }
        }
    }
    cout<<kind<<endl;
}