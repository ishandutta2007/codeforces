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
        int n;
        string s;
        cin>>n>>s;
        if(n>2){cout<<"NO"<<endl;continue;}
        if(n==2 && s[0]==s[1]){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
    }
    return 0;
}