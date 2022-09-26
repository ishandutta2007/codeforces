#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

int n = 5;
int ost(vector<int> a, vector<int> b)
{
    int sa = 0;
    int sb = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        sa+=a[i];
        c++;
        if (sa > sb + n - i)
            return c;
        if (sb > sa + n - 1 - i)
            return c;

        sb+=b[i];
        c++;
        if (sb > sa + n - 1 - i)
            return c;
        if (sa > sb + n - 1 - i)
            return c;
    }
    return 2*n;
}

int res(string s)
{
    vector<int> v1 ,v2;
    for (int i=0; i<s.size(); i++)
    {
        if (i%2==0) v1.pb(s[i] - '0');
        else v2.pb(s[i] - '0');
    }
    return ost(v1, v2);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 1; _ <= ___; _++)
    {
        string s;
        cin>>s;

        string t = s;
        for (int i=0; i<2*n; i++)
        {
            if (s[i]=='?')
                s[i] = ('0' + (i%2));
            if (t[i]=='?')
                t[i] = ('1' - (i%2));
        }

//            cout<<s<<" "<<t<<"\n";
        cout<<min(res(s), res(t))<<"\n";
    }
}