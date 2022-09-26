#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax = 2e5 + 100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 0; _ < ___; _++)
    {
        string s;
        cin>>s;
        int n=s.size();
//        vector<int> dp(n);
//        dp[0]=0;
//        for (int i=1; i<n; i++)
//        {
//            dp[i]=dp[i-1]+1;
//
//            if (s[i] == s[i-1])
//            {
//
//            }
//            else
//            if ((i>1) and (is[i] == s[i-2]))
//            {
//
//            }
//            else
//                dp[i]=dp[i-1];
//        }

        vector<int> ch(n);
        int ans=0;
        for (int i=1; i<n; i++)
        {
            if ((s[i]==s[i-1]) and (ch[i-1]==0))
                ch[i]=1, ans++;
            else
            if (i>1)
            if ((s[i]==s[i-2]) and (ch[i-2]==0))
                ch[i]=1, ans++;
        }
        cout<<ans<<"\n";
    }
}