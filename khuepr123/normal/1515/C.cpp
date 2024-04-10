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
int n, m, a[maxN];
int x, y, z, k;
int b[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m >> x;
        for1(i, 1, n){
            cin >> a[i];
        }
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for1(i, 1, m){
            pq.push(ii(0, i));
        }
        for1(i, 1, n){
            ii pr = pq.top(); pq.pop();
            pr.fi = pr.fi + a[i];
            b[i] = pr.se;
            pq.push(pr);
        }
        cout << "YES\n";
        for1(i, 1, n){
            cout << b[i] << " ";
        }
        cout << endl;
    }
}