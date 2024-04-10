#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int d=0;
    for(int i=1;i<10000;i++)
    {
        d+=i;
        if(d==n+1){cout<<i+1<<endl;break;}
        if(d>=n){cout<<i<<endl;break;}

    }
    }
    return 0;
}