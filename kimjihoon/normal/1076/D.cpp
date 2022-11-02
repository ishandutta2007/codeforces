#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define ll long long

struct vd
{
    int tn, i;
    ll w;
    vd(int tn, ll w, int i) : tn(tn), w(w), i(i) {};
    vd() : tn(0), w(0), i(0) {};
};

vector<vd> v[300009];
vector<int> rv[300009];
ll ds[300009];
bool er[300009], vs[300009];

void dfs(int hn, int d)
{
    vs[hn] = true;
    int ri = 0;
    for (int i = 0; i < v[hn].size(); i++){
        int tn = v[hn][i].tn, ti = v[hn][i].i;
        if (er[ti]) continue;
        if (vs[tn])
            ri = ti;
        else
            dfs(tn, d + 1);
    }
    if (d > 0) rv[d].push_back(ri);
}

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    for (int i = 0; i < m; i++){
        int a, b; ll w;
        cin>>a>>b>>w; a--; b--;
        v[a].push_back(vd(b, w, i));
        v[b].push_back(vd(a, w, i));
    }
    for (int i = 0; i < n; i++)
        ds[i] = 1000000000000000000LL;
    ds[0] = 0;
    q.push(make_pair(0, 0));
    while (!q.empty()){
        if(q.top().first != ds[q.top().second])
        {
            q.pop();
            continue;
        }
        int hn = q.top().second; q.pop();
        for (int i = 0; i < v[hn].size(); i++){
            int tn = v[hn][i].tn; ll w = v[hn][i].w;
            if (ds[tn] > ds[hn] + w){
                ds[tn] = ds[hn] + w;
                q.push(make_pair(ds[tn], tn));
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (ds[i] == 1000000000000000000LL)
            for (int j = 0; j < v[i].size(); j++)
                er[v[i][j].tn] = true;
    for (int i = 0; i < n; i++){
        int r = 0;
        for (int j = 0; j < v[i].size(); j++){
            int tn = v[i][j].tn, ti = v[i][j].i; ll w = v[i][j].w;
            if (er[ti]) continue;
            if (ds[i] + w != ds[tn] && ds[tn] + w != ds[i])
                er[ti] = true;
            else if (ds[tn] + w == ds[i]){
                if (r > 0)
                    er[ti] = true;
                r++;
            }
        }
    }
    int s = 0;
    for (int i = 0; i < m; i++)
        s += (int)er[i];
    if (m - s > k){
        dfs(0, 0);
        int r = m - s - k;
        for (int i = n; i >= 0 && r; i--)
            for (int j = 0; j < rv[i].size(); j++){
                er[rv[i][j]] = true;
                r--;
                if (!r) break;
            }
    }
    cout<<k<<'\n';
    int c = 0;
    for (int i = 0; i < m && c < k; i++){
        if (!er[i]){
            cout<<i + 1<<" ";
            c++;
        }
    }
    for (int i = 0; i < m && c < k; i++){
        if (er[i]){
            cout<<i + 1<<" ";
            c++;
        }
    }
    cout<<'\n';
    return 0;
}