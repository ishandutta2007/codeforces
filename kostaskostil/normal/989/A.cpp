#include <bits/stdc++.h>

using namespace std;

int n,a,c;

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    c=0;
    for (int i=1; i<s.size()-1; i++)
    {
        if ((s[i-1]=='A') and (s[i]=='B') and (s[i+1]=='C'))
            c=1;
        if ((s[i-1]=='A') and (s[i]=='C') and (s[i+1]=='B'))
            c=1;
            if ((s[i-1]=='B') and (s[i]=='A') and (s[i+1]=='C'))
            c=1;
            if ((s[i-1]=='B') and (s[i]=='C') and (s[i+1]=='A'))
            c=1;
            if ((s[i-1]=='C') and (s[i]=='A') and (s[i+1]=='B'))
            c=1;
            if ((s[i-1]=='C') and (s[i]=='B') and (s[i+1]=='A'))
            c=1;
    }

    if (c==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}