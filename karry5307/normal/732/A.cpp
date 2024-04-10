#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cost,coin;
int main()
{
    cin>>cost>>coin;
    for(register int i=1;i<=10;i++)
    {
        if(cost*i%10==0||cost*i%10==coin)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}