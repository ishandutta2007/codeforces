#include <bits/stdc++.h>

using namespace std;

queue <int> s1, s2;
int n, k1, k2, a, ans;

int main()
{
    cin>>n;
    cin>>k1;
    for(int i=1;i<=k1;i++)
        cin>>a, s1.push(a);

    cin>>k2;
    for(int i=1;i<=k2;i++)
        cin>>a, s2.push(a);

    while(ans<2000000)
    {
        int x1=s1.front();
        int x2=s2.front();
        s1.pop();
        s2.pop();
        if(x1<x2)
        {
            s2.push(x1);
            s2.push(x2);
        }
        else if(x1>x2)
        {
            s1.push(x2);
            s1.push(x1);
        }
    ans++;
    if(s1.empty())
    {
        cout<<ans<<' '<<2;
        return 0;
    }
    if(s2.empty())
    {
        cout<<ans<<' '<<1;
        return 0;
    }
    }

    cout<<-1;
    return 0;
}