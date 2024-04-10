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
        char x,y;
        cin>>x>>y;
        int ans=(x-'a')*25+y-'a'+1;
        if(y>x)ans--;
        cout<<ans<<endl;
    }

    return 0;
}