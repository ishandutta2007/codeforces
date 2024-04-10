#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(y%x){cout<<0<<" "<<0<<endl;continue;}
        cout<<1<<" "<<y/x<<endl;
    }

    return 0;
}