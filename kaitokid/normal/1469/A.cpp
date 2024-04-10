#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
ios::sync_with_stdio(0);
int t;
string s;
cin>>t;
while(t--)
{
    cin>>s;
    if(s.size()%2){cout<<"NO\n";continue;}
    if(s[0]==')'||s[s.size()-1]=='(')cout<<"NO\n";
    else cout<<"YES\n";
}
    return 0;
}