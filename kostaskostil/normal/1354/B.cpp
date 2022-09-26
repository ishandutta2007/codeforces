#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        string s;
        cin>>s;
        int n=s.size();
        vector<int> on(n, -1e9);
        vector<int> tw(n, -1e9);
        vector<int> tr(n, -1e9);
        if (s[0]=='1') on[0]=0;
        else if (s[0]=='2') tw[0]=0;
        else tr[0]=0;
        for (int i=1; i<n; i++)
        {
            on[i]=on[i-1];
            tw[i]=tw[i-1];
            tr[i]=tr[i-1];
        if (s[i]=='1') on[i]=i;
        else if (s[i]=='2') tw[i]=i;
        else tr[i]=i;
        }
        int ans=1e9;
        for (int i=0; i<n; i++)
            ans=min(ans, max(max(i-on[i], i-tw[i]), i-tr[i]));
        if (ans<n+100)
            cout<<ans+1<<"\n";
        else cout<<0<<"\n";
    }

    return 0;
}