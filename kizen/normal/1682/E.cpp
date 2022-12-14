#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int NS = (int)2e5 + 4;
int n, q;
int a[NS];
vector<pair<int, int>> way[NS];
int chk[NS], num[NS], low[NS], high[NS], id[NS];
vector<int> ans;
int inc, sz;

void dfs(int x, int pr){
    id[x] = x;
    low[x] = high[x] = num[x];
    vector<pair<int, int>> nv;
    for(auto&nxt:way[x]){
        if(nxt.first == pr){
            continue;
        }
        nv.push_back(nxt);
        dfs(nxt.first, x);
        mi(low[x], low[nxt.first]);
        ma(high[x], high[nxt.first]);
    }
    sort(nv.begin(), nv.end(), [&](pair<int, int>&x, pair<int, int>&y){return low[x.first] < low[y.first];});
    while(num[id[x]] + 1 <= high[x]){
        int l = 0, r = (int)nv.size() - 1, mid;
        while(l < r){
            mid = l + r + 1 >> 1;
            if(low[nv[mid].first] <= num[id[x]] + 1){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        ans.push_back(nv[l].second);
        swap(id[x], id[nv[l].first]);
    }
}

void dfs2(int x, int pr){
    vector<pair<int, int>> nv;
    for(auto&nxt:way[x]){
        if(nxt.first == pr){
            continue;
        }
        nv.push_back(nxt);
    }
    sort(nv.begin(), nv.end(), [&](pair<int, int>&x, pair<int, int>&y){return low[x.first] < low[y.first];});
    while(num[id[x]] % sz + 1 != num[x]){
        int l = 0, r = (int)nv.size() - 1, mid;
        while(l < r){
            mid = l + r + 1 >> 1;
            if(low[nv[mid].first] <= num[id[x]] + 1){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        ans.push_back(nv[l].second);
        swap(id[x], id[nv[l].first]);
    }
    for(auto&nxt:way[x]){
        if(nxt.first == pr){
            continue;
        }
        dfs2(nxt.first, x);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= q; ++i){
        int x, y; cin >> x >> y;
        way[x].push_back({y, i});
        way[y].push_back({x, i});
    }
    for(int i = 1; i <= n; ++i){
        if(chk[i]){
            continue;
        }
        chk[i] = 1;
        int cnt = 0;
        num[i] = ++cnt;
        int j = a[i];
        sz = 1;
        while(j != i){
            ++sz;
            chk[j] = 1;
            num[j] = ++cnt;
            j = a[j];
        }
//        for(int j = 1; j <= 6; ++j){
//            cout << j << ' ' << num[j] << endl;
//        }
//        cout << endl;
        dfs(i, -1);
        dfs2(i, -1);
    }
    for(auto&i:ans){
        cout << i << ' ';
    }
    return 0;
}