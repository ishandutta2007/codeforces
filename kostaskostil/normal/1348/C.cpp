#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=5e5+100;
#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        if (s[0]==s[k-1])
        {
            int a[26];
            for (int i=0; i<26; i++) a[i]=0;
            for (int i=k; i<s.size(); i++)
                a[s[i]-'a']++;
            vector<int> v;
            for (int i=0; i<26; i++)
                if (a[i])
                    v.pb(i);

            if (v.size()>1)
                cout<<s.substr(k-1, s.size()-k+1)<<"\n";
            else
            if (v.size()==1)
                cout<<s[0]<<string((a[v[0]]+k-1)/k, 'a'+v[0])<<"\n";
            else
                cout<<s[0]<<"\n";
        }
        else cout<<s[k-1]<<"\n";
    }
}