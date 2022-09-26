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

    string s1, s2;
    cin>>s1>>s2;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cout<<s1<<" "<<s2<<"\n";
        string s, t;
        cin>>s>>t;
        if (s==s1)
            s1=t;
        else
            s2=t;
    }
    cout<<s1<<" "<<s2<<"\n";
}