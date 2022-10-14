#include<bits/stdc++.h>
#define maxn 200200
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,ans[maxn],l[maxn],r[maxn],a[maxn];
set<ii> sett;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w".stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        sett.insert(ii{a[i],i});
    }

    r[n+1] = n+1;
    for(int i=1; i<=n; i++)
        l[i] = i - 1, r[i] = i + 1;

    int cnt = 1;
    while( sett.size() ){
        auto Qt = sett.end();
        Qt--;
        ii qt = *Qt;

        vector<int> v;
        int h = l[qt.s];
        for(int i=1; i<=k; i++){
            ans[h] = cnt;
            sett.erase(ii{a[h],h});
            v.push_back(h);
            h = l[h];
        }

        h = r[qt.s];
        for(int i=1; i<=k; i++){
            ans[h] = cnt;
            sett.erase(ii{a[h],h});
            v.push_back(h);
            h = r[h];
        }

        ans[qt.s] = cnt;
        sett.erase(ii{qt.f,qt.s});
        v.push_back(qt.s);

        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++)
            l[v[i]] = l[v[0]], r[v[i]] = r[v[(int)v.size()-1]];
        r[l[v[0]]] = r[v[(int)v.size()-1]];
        l[r[(int)v[v.size()-1]]] = l[v[0]];

        cnt = ( ( cnt - 1 ) ^ 1 ) + 1;
    }

    for(int i=1; i<=n; i++)
        cout << ans[i];

    return 0;
}