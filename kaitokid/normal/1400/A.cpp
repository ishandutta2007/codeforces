#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)cout<<s[n-1];
        cout<<endl;
    }
    return 0;
}