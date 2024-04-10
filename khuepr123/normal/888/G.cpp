#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

struct maketrie{
    int chi[2];
} trie[maxN * 10];
int cnt = 0;

void init(int ind){
    memset(trie[ind].chi, -1, sizeof(trie[ind].chi));
}

void push(int num){
    int pt = 0;
    for2(i, 29, 0){
        bool bk = (num & (1ll << i));
        if(trie[pt].chi[bk] == -1){
            init(++cnt);
            trie[pt].chi[bk] = cnt; pt = cnt;
        }
        else pt = trie[pt].chi[bk];
    }
}

int best(int num){
    int pt = 0;
    int res = 0;
    for2(i, 29, 0){
        bool bk = (num & (1ll << i));
        if(trie[pt].chi[bk] == -1){
            res |= (1ll << i); bk = !bk;
        }
        pt = trie[pt].chi[bk];
    }
    return res;
}

void clean(){
    for1(i, 0, cnt){
        init(i);
    }
    cnt = 0;
}

queue<pair<vector<int>, int>> q;
vector<int> vander; int bt;
int ans = 0;

void solve(){
    if(vander.size() < 2) return;
    vector<int> v[2];
    clean();
    int res = 0;
    for(int child : vander){
        bool bk = child & (1ll << bt);
        v[bk].pb(child);
    }
    if(v[0].size() && v[1].size()){
        res = oo;
        for(int child : v[0]) push(child);
        for(int child : v[1]) res = min(res, best(child));
    }
    ans += res;
    if(bt){
        q.push(make_pair(v[0], bt - 1));
        q.push(make_pair(v[1], bt - 1));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    init(0);
    set<int> dumbest;
    cin >> n;
    for1(i, 1, n){
        cin >> x;
        dumbest.insert(x);
    }
    n = dumbest.size();
    for(int child : dumbest){
        vander.pb(child);
    }
    q.push(make_pair(vander, 29));
    while(!q.empty()){
        vander = q.front().fi;
        bt     = q.front().se;
        q.pop();
        solve();
    }
    cout << ans << endl;
}