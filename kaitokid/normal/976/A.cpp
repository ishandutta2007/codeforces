#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int n;
    string s;
    cin>>n>>s;
    if(s=="0"){cout<<0;return 0;};
    int u=0;
    for(int i=0;i<n;i++)
        if(s[i]=='0')u++;
    cout<<1;
    for(int i=0;i<u;i++)
        cout<<0;
    return 0;
}