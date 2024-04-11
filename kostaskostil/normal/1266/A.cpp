#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        int sm=0;
        bool f1=false;
        int f2=0;
        cin>>s;
        for (char c:s)
        {
            if (c=='0')
                f1=true;
            if (((c-'0')%2)==0)
                f2++;
            sm+=(c-'0');
        }
        if (f1 and (f2>1) and (sm%3==0))
            cout<<"red\n";
        else
            cout<<"cyan\n";
    }
}