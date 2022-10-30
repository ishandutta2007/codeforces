// Hydro submission #631f2f6432ae6c3198c90d83@1662988133497
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        sort(s.begin(),s.end());
        printf(s=="Timru"?"YES\n":"NO\n");
    }
    return 0;
}