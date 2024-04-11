#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=1e6+100;
typedef long long ll;
#define int ll

int n;
int a[nmax];
int used[nmax];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i], a[i]=i-a[i];
        for (int i=1; i<=n; i++)
            used[i]=0;

        int cur=1;
        while (!used[cur]){
            used[cur]=1;
            cur=a[cur];
        }
        int start=cur;
        cur=a[cur];
        vector<int> ans={start};
        while (cur!=start)
            ans.pb(cur), cur=a[cur];
        cout<<ans.size()<<"\n";
        for (int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}