#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n; int q; int a[maxN];
map<int, int> mp;
int pre[maxN];
int pr;

void process(int left, int right){
    if(left > right){
        cout << "BUG"; return;
    }
    if(left == right){
        mp.insert(pair<int, int>(a[left], 0)); return;
    }
    int mid = (a[left] + a[right]) / 2;
    mp.insert(pair<int, int>(pre[right] - pre[left - 1], 0));
    int cur = right + 1;
    for(int i = left; i <= right; i++){
        if(a[i] > mid){
            cur = i; break;
        }
    }
    if(a[right] == a[left]) return;
    process(left, cur - 1);
    process(cur, right);
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        mp.clear();
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + a[i];
        }
        process(1, n);
        
        while(q--){
            cin >> pr;
            if(mp.find(pr) != mp.end()) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}