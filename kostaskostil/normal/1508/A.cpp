#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int cnt(string s, char c)
{
    int a = 0;
    for (char cx : s)
        if (cx == c)
            a++;
    return a;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        int n;
        cin>>n;
        string s1, s2, s3;
        cin>>s1>>s2>>s3;

        vector<string> v1;
        vector<string> v2;

        if (cnt(s1, '1') > n)
            v1.pb(s1);
        else
            v2.pb(s1);
        if (cnt(s2, '1') > n)
            v1.pb(s2);
        else
            v2.pb(s2);
        if (cnt(s3, '1') > n)
            v1.pb(s3);
        else
            v2.pb(s3);

        bool inv = false;
        if (v2.size() > 1)
        {
            v1 = v2;
            inv = true;
            for (string& s : v1)
                for (char& c : s)
                    c = '1'+'0'-c;
        }

        string q = v1[0];
        string t = v1[1];
        string res;

        int pos = 0;

        for (char c : q)
        {
            while ((pos<2*n) and (t[pos]=='0'))
                res+='0', pos++;
            if (c=='0')
                res+='0';
            else
                res+='1', pos++;
        }
        while (pos<2*n)
            res+=t[pos++];
        if (inv)
        {
            for (char c: res)
                cout<<char('0'+'1'-c);
            cout<<"\n";
        }
        else
            cout<<res<<"\n";
    }
}