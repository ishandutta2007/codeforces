#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
vector<int> a, b;
int nn, mm;
bool asd[1005][1005];

bool bipartiteMatch(int u, bool visited[], int assign[]) {
   for (int v = 0; v < nn; v++) {    //for all jobs 0 to N-1
        if (asd[u][v] && !visited[v]) {    //when job v is not visited and u is interested
            visited[v] = true;    //mark as job v is visited
            //when v is not assigned or previously assigned
            if (assign[v] < 0 || bipartiteMatch(assign[v], visited, assign)) {
               assign[v] = u;    //assign job v to applicant u
               return true;
            }
        } 
   }
   return false;
}
void solve(int TC) {
    int assign[1005];
    bool visited[1005];
    int n, m;
    cin >> n >> m;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        if(x * 2 >= m) {
            cout << "-1\n";
            return;
        }
        if(x * 3 > m) a.pb(x);
        else b.pb(x);
    }
    mm = a.size();
    nn = b.size();
    for(int i = 0; i < 1000; i++) assign[i] = -1;
    for(int i = 0; i < mm; i++) {
        for(int j = 0; j < nn; j++) {
            if(a[i] % b[j] == 0 && a[i] * 2 + b[j] <= m) {
                asd[i][j] = true;
            }
        }
    }
    int tc = 0;
    for(int i = 0; i < mm; i++) {
        for(int j = 0; j < nn; j++) visited[j] = false;
        if(bipartiteMatch(i, visited, assign)) tc++;
    }
    if(tc < mm) {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> ans;
    map<int, bool> dead;
    int rev[1005];
    for(int i = 0; i < nn; i++) {
        if(assign[i] >= 0) rev[assign[i]] = i;
    }
    for(int i = 0; i < mm; i++) {
        // cout << "edge: " << a[i] << ' ' << b[rev[i]] << '\n';
        ans.pb(mp(a[i] + b[rev[i]], a[i] * 2 + b[rev[i]]));
        dead[rev[i]] = true;
    }
    for(int i = 0; i < nn; i++) {
        if(!dead[i]) ans.pb(b[i] * 2, b[i] * 3);
    }
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x.fi << ' ' << x.se << '\n';return;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}