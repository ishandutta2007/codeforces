#include <bits/stdc++.h>
#define y1 y_1
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int nmax = 1000500;

string s;
string get(int k)
{
    string q;
    for (int i=0; i<k; i++)
        q+=s[i];
    for (int i=k-1; i>=0; i--)
        q+=s[i];
    return q;
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
        cin>>s;
        string mn = get(1);
        int r = 120;
        for (int i=1; i<=n; i++)
        {
            if (i-2>=0)
                if (i+1<n)
                    if ((s[i-2] == s[i-1]) && (s[i-1] == s[i]) && (s[i] == s[i+1]))
                        continue;
            r--;
            mn = min(mn, get(i));
            if (r==0)
                break;
        }
        cout<<mn<<"\n";
    }

}