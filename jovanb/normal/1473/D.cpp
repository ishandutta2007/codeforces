#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

const int MAXN = 200005;

int premax[MAXN], premin[MAXN], sufmax[MAXN], sufmin[MAXN], pre[MAXN];

void solve(){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int i=0; i<=n+2; i++) pre[i] = premax[i] = premin[i] = sufmax[i] = sufmin[i] = 0;
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1];
        if(s[i-1] == '+') pre[i]++;
        else pre[i]--;
        premax[i] = pre[i];
        premax[i] = max(premax[i], premax[i-1]);
        premin[i] = pre[i];
        premin[i] = min(premin[i], premin[i-1]);
    }
    int ts = 0;
    for(int i=n; i>=1; i--){
        int koji = 0;
        if(s[i-1] == '+'){
            ts++;
            koji = 1;
        }
        else {
            ts--;
            koji = -1;
        }
        sufmin[i] = min(min(0, ts), sufmin[i+1]+koji);
        sufmax[i] = max(max(0, ts), sufmax[i+1]+koji);
    }
    while(t--){
        int l, r;
        cin >> l >> r;
        int mx = max(premax[l-1], pre[l-1] + sufmax[r+1]);
        int mn = min(premin[l-1], pre[l-1] + sufmin[r+1]);
        cout << mx-mn+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}