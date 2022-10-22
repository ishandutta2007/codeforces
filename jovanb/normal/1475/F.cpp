#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

int a[1005][1005];
int b[1005][1005];
vector <int> graf[4005];
int comp[4005];

int nc;
int n;

int ne(int x){
    if(x <= 2*n) return x+2*n;
    return x-2*n;
}

void dfs(int v){
    comp[v] = nc;
    for(auto c : graf[v]) if(!comp[c]) dfs(c);
}

bool solve(){
    cin >> n;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=n; j++){
            if(s[j-1] == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=n; j++){
            if(s[j-1] == '1') b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    for(int i=1; i<=4*n; i++) graf[i].clear();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] != b[i][j]){
                graf[i].push_back(ne(j+n));
                graf[ne(i)].push_back(j+n);
                graf[j+n].push_back(ne(i));
                graf[ne(j+n)].push_back(i);
            }
            else{
                graf[i].push_back(j+n);
                graf[ne(i)].push_back(ne(j+n));
                graf[j+n].push_back(i);
                graf[ne(j+n)].push_back(ne(i));
            }
        }
    }
    for(int i=1; i<=4*n; i++){
        comp[i] = 0;
    }
    for(int i=1; i<=2*n; i++){
        if(!comp[i]){
            nc++;
            dfs(i);
        }
    }
    for(int i=1; i<=2*n; i++){
        if(comp[i] == comp[ne(i)]) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}