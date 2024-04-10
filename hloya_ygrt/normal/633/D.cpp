#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define ll long long
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>


const int maxn = 2e5+500;
const int inf = 1e9;
const double eps = 1e-7;
const int base = 1073676287;
using namespace std;

int a[maxn];
unordered_map<int,int> sot;
int ans = 0;

int main()
{
    int n;
    scanf("%d", &n);
    forn()
        scanf("%d", a + i), sot[a[i]]++;

    ans = max(ans, sot[0]);

    for (int f = 0 ; f < n; f++){
        for (int s = 0 ; s < n; s++){
            if (f == s)
                continue;
            if (a[f] == a[s] && a[f] == 0)
                continue;
            vector<ll> got;
            got.pb(a[f]), got.pb(a[s]);
            sot[a[f]]--;
            sot[a[s]]--;

            while (1)
            {
                ll need = got.back() + *(--(--got.end()));
                if (sot.find(need) == sot.end() || sot[need] == 0)
                    break;
                sot[need] --;
                got.pb(need);
            }

            ans = max(ans, (int)got.size());
            for (int j=0;j<got.size();j++){
                sot[got[j]]++;
            }
        }
    }

    cout << ans;
    return 0;
}