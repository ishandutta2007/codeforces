#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=100500;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {

        string s;
        int n;
        cin>>n;
        cin>>s;
        bool f=false;
        string a="1";
        string b="1";
        for (int i=1; i<n; i++)
        {
            if (s[i]=='0')
                a+="0", b+="0";
            if (s[i]=='1')
            {
                if (f)
                    a+="0", b+="1";
                else
                    a+="1", b+="0", f=true;
            }
            if (s[i]=='2')
            {
                if (f)
                    a+="0", b+="2";
                else
                    a+="1", b+="1";
            }
        }
        cout<<a<<"\n";
        cout<<b<<"\n";
    }
}