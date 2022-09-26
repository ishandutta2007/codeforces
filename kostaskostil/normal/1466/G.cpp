#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

//const int nmax = 1e6 + 100;
const int mmax = 1e5 + 100;

const int MOD = 1e9 + 7;

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

pair<int, vector<int> > procedure(string s, string t, bool dual = true)
{
    int n = s.size();
    int m = t.size();

    vector<int> normal = z_function(t + "#" + s);

    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());

    vector<int> rev = z_function(t + "#" + s);

    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());

    int cnt=0;
    for (int i=m+1; i<n+m+1; i++)
        if (normal[i]==m)
            cnt++;

    vector<int> res(26, 0);

    if (dual)
    {
        for (int i=0; i<m; i++)
        {
            if ((i==0) or (normal[n+m+1-i]==i))
            if ((i==m-1) or (rev[n+m+1-(m-i-1)]==m-i-1))
                res[t[i]-'a']++;
        }
    }

//    cout<<s<<" "<<t<<"\n";
//    cout<<cnt<<"\n";
//    for (int i=0; i<26; i++)
//        if (res[i]!=0)
//            cout<<char(i+'a')<<" "<<res[i]<<"\n";

    return {cnt, res};
}

int n, q;
string s0;
string t;
int letter[mmax][26];
int pw[mmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    auto pa = procedure("zxyxyzxxyz", "xyz");
//    return 0;

    cin>>n>>q;
    cin>>s0>>t;
    t = "*" + t;

    pw[0]=1;
    for (int i=1; i<mmax; i++)
        pw[i]=(2*pw[i-1])%MOD;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<26; j++)
            letter[i][j]=(2*letter[i-1][j])%MOD;
        letter[i][t[i]-'a']++;
        letter[i][t[i]-'a']%=MOD;
    }
    for(int _=0; _<q; _++)
    {
        int ind;
        string w;
        cin>>ind>>w;

        int cur = 0;
        string s = s0;
        while ((s.size() < w.size()) and (cur < ind))
        {
            cur++;
            s=s+t[cur]+s;
        }

        if (s.size() < w.size())
            cout<<0<<"\n";
        else
        {
            auto pa = procedure(s, w);

            int ans = (pa.fi * pw[ind-cur])%MOD;
            for (int i=0; i<26; i++)
            {
                int cntletters = letter[ind][i] - (pw[ind-cur]*letter[cur][i])%MOD;
                if (cntletters<0) cntletters+=MOD;

                ans = (ans + pa.se[i]*cntletters)%MOD;
            }
            cout<<ans<<"\n";
        }
    }
}