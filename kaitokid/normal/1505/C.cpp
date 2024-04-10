#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;

    for(int i=2;i<s.size();i++)
    {
        int r1=s[i-2]-'A';
        int r2=s[i-1]-'A';
        int r3=s[i]-'A';
        if(r3!=(r1+r2)%26){cout<<"NO";return 0;}

    }
    cout<<"YES";
        return 0;
}