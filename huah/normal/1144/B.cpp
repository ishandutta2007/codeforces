#include<bits/stdc++.h>
using namespace std;
priority_queue<int>a,b;
int main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans+=x;
        if(x%2) a.push(x);
        else b.push(x);
    }
    if(a.size()<b.size()) swap(a,b);
    int v=0;
    while(1)
    {
        if(v==0)
        {
            if(a.size())
                ans-=a.top(),a.pop();
            else break;
        }
        else
        {
            if(b.size())
                ans-=b.top(),b.pop();
            else break;
        }
        v^=1;
    }
    cout<<ans<<endl;
}