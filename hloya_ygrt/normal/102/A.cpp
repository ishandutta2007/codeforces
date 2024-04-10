#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e2+500, base = 1e9+7,maxm= 1e4+5;

int c[maxn];

set<int> sot[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> c[i];

    }

    for (int i=0;i<m;i++){
        int f,t;
        cin >> f >> t;
        f--;
        t--;
        sot[f].insert(t);
        sot[t].insert(f);
    }
    int ans = inf;
    for (int f = 0; f < n;f++){
    for (int s = 0; s < n;s++){
    for (int t = 0; t < n;t++){
        if (sot[f].count(s) && sot[f].count(t) && sot[s].count(t)){
            ans = min(ans, c[f] + c[s] + c[t]);
        }
    }
    }
    }
    if (ans == inf)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}