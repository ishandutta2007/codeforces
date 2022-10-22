#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int in[500005];
int out[500005];
vector <int> graf[500005];
vector <pair <int, int>> vec[500005];

int cnt;
string s;

void dfs(int v, int depth){
    in[v] = ++cnt;
    int k = s[v-1]-'a';
    if(vec[depth].size() == 0) vec[depth].push_back({in[v], (1 << k)});
    else vec[depth].push_back({in[v], vec[depth].back().second ^ (1 << k)});
    for(auto c : graf[v]){
        dfs(c, depth+1);
    }
    out[v] = cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        graf[x].push_back(i);
    }
    cin >> s;
    dfs(1, 1);
    while(m--){
        int a, b;
        cin >> a >> b;
        int tl = in[a];
        int tr = out[a];
        n = vec[b].size();
        int g=-1, l=0, r=n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(vec[b][mid].first <= tl-1){
                l = mid+1;
                g = mid;
            }
            else r = mid-1;
        }
        int d = -1;
        l=0, r=n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(vec[b][mid].first <= tr){
                l = mid+1;
                d = mid;
            }
            else r = mid-1;
        }
        int x;
        if(d < 0) x = 0;
        else x = vec[b][d].second;
        if(g >= 0) x ^= vec[b][g].second;
        //cout << x << endl;
        if(__builtin_popcount(x) <= 1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}