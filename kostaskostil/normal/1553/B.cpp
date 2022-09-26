#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

bool substring(string s, string t)
{
    string res = t + '#' + s;
    auto v = z_function(res);
    for (int i : v)
        if (i == t.size())
            return true;
    return false;
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
        string s, t;
        cin>>s>>t;
        bool ok = false;
        for (int i=0; i<s.size(); i++)
        {
            string h = "";
            for (int j=0; j<=i; j++)
                h+=s[j];
            for (int j=i-1; j>=0; j--)
                h+=s[j];
            if (substring(h, t))
                ok = true;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}