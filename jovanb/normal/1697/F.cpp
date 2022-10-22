#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

vector <int> graf[N+5];
vector <int> rgraf[N+5];

int n, m, k;

bool visited[N+5];

vector <int> st;

int comp[N+5];

int tjm;

void dfs_rev(int v){
    comp[v] = tjm;
    for(auto c : rgraf[v]){
        if(!comp[c]) dfs_rev(c);
    }
}

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]){
        if(!visited[c]) dfs(c);
    }
    st.push_back(v);
}

void sledi(int x, int y){
    //cout << x << " u " << y << endl;
    graf[x].push_back(y);
    rgraf[y].push_back(x);
}

int veci(int x, int y){
    return n*(k + 1) + (k + 1)*(x - 1) + y + 1;
}

int mjd(int x, int y){
    return (k + 1)*(x - 1) + y + 1;
}

bool tacno[N+5];
int niz[N+5];

void solve(){
    cin >> n >> m >> k;
    tjm = 0;
    for(int i=1; i<=2*n*(k+1); i++){
        graf[i].clear();
        rgraf[i].clear();
        tacno[i] = 0;
        comp[i] = 0;
        visited[i] = 0;
    }
    st.clear();
    for(int i=1; i<=n; i++){
        sledi(veci(i, k), mjd(i, 0));
        sledi(mjd(i, 0), veci(i, k));
        for(int j=0; j<=k; j++){
            if(j >= 1){
                sledi(veci(i, j), veci(i, j - 1));
                sledi(mjd(i, j - 1), mjd(i, j));
            }
            if(i > 1){
                sledi(veci(i - 1, j), veci(i, j));
                sledi(mjd(i, j), mjd(i - 1, j));
            }
        }
    }
    while(m--){
        int typ;
        cin >> typ;
        if(typ == 1){
            int i, x;
            cin >> i >> x;
            if(x == 1){
                sledi(mjd(i, x), veci(i, k));
            }
            else if(x == k){
                sledi(mjd(i, x), mjd(i, x - 1));
                sledi(veci(i, k - 1), veci(i, k));
            }
            else{
                sledi(mjd(i, x), mjd(i, x - 1));
                sledi(veci(i, x - 1), veci(i, x));
            }
        }
        else if(typ == 2){
            int i, j, x;
            cin >> i >> j >> x;
            for(int h=0; h<=k; h++){
                int g = x - h;
                if(g > k) continue;
                if(g <= 1){
                    sledi(veci(i, h), mjd(i, 0));
                    sledi(veci(j, h), mjd(j, 0));
                }
                else{
                    sledi(veci(i, h), mjd(j, g - 1));
                    sledi(veci(j, h), mjd(i, g - 1));
                }
            }
        }
        else{
            int i, j, x;
            cin >> i >> j >> x;
            for(int h=0; h<=k; h++){
                int g = x - h;
                if(g <= 1) continue;
                if(g > k){
                    sledi(mjd(i, h), veci(i, k));
                    sledi(mjd(j, h), veci(j, k));
                }
                else{
                    sledi(mjd(i, h), veci(j, g - 1));
                    sledi(mjd(j, h), veci(i, g - 1));
                }
            }
        }
    }
    for(int i=1; i<=2*n*(k+1); i++){
        if(!visited[i]) dfs(i);
    }
    reverse(st.begin(), st.end());
    for(auto c : st){
        if(!comp[c]){
            ++tjm;
            dfs_rev(c);
        }
    }
    for(int i=1; i<=n*(k+1); i++){
        if(comp[i] == comp[i + n*(k+1)]){
            cout << "-1\n";
            return;
        }
        if(comp[i] > comp[i + n*(k+1)]) tacno[i] = 1;
    }
    for(int i=1; i<=n; i++) niz[i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=k; j>=0; j--){
            if(tacno[mjd(i, j)]) niz[i] = j;
        }
    }
    for(int i=1; i<=n; i++){
        assert(niz[i]);
        cout << niz[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}