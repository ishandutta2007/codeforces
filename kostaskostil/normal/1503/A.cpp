#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 1e6+100;

typedef long long ll;
#define int ll

template<typename T>
istream& operator >> (istream& is, vector<T>& v)
{
    for (T& i : v)
        is>>i;
    return is;
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
        string s;
        cin>>n>>s;
        int diff=0;
        for (char c: s)
            if (c == '0')
                diff++;

        int eq = n - diff;

        if (eq % 2 != 0)
        {
            cout<<"NO\n";
            continue;
        }

        int l = eq/2;
        string a1, a2;
        int c1=0, c2=0;
        bool f = true;
        for (int i=0; i<n; i++)
        {
            if (s[i] == '1')
            {
                if (l>0)
                {
                    a1+='(';
                    a2+='(';
                    c1++;
                    c2++;
                    l--;
                }
                else
                {
                    a1+=')';
                    a2+=')';
                    c1--;
                    c2--;
                }
            }
            else
            {
                if (c1 > c2)
                {
                    a1+=')';
                    c1--;
                    a2+='(';
                    c2++;
                }
                else
                {
                    a1+='(';
                    c1++;
                    a2+=')';
                    c2--;
                }
            }
            if ((c1<0) or (c2<0))
                f=false;
        }
        if ((c1!=0) or (c2!=0))
            f=false;

        if (f)
        {
            cout<<"YES\n"<<a1<<"\n"<<a2<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}