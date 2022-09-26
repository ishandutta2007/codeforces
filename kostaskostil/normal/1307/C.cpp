#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long
using namespace std;

int p[100500][26];
int ans[26][26];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<26; j++)
        {
            p[i][j]=p[i-1][j];
            if (s[i-1]-'a'==j)
                p[i][j]++;
        }
    }
    int answ=0;
    for (int i=0; i<26; i++)
        answ=max(answ, p[n][i]);
    for (int i=1; i<=n; i++)
        for (int j1=0; j1<26; j1++)
            ans[j1][s[i-1]-'a']+=p[i-1][j1];
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            answ=max(answ, ans[i][j]);
    cout<<answ<<"\n";
    return 0;
}