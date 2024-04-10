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
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, m;
string s, t;


int cls[maxN];
int far[maxN];
int mx = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    s = "#" + s;
    t = "#" + t;
    int cur = 1;
    for(int i = 1; i <= n; i++){
        if(cur > m) break;
        if(s[i] == t[cur]){
            cls[cur] = i;
            cur++;
        }
    }
    cur = m;
    for(int i = n; i > 0; i--){
        if(cur == 0) break;
        if(s[i] == t[cur]){
            far[cur] = i;
            cur--;
        }
    }
    for(int i = 1; i < n; i++){
        mx = max(mx, far[i + 1] - cls[i]);
        mx = max(mx, cls[i + 1] - cls[i]);
        mx = max(mx, far[i + 1] - far[i]);
    }
    cout << mx + 1 - 1;
}