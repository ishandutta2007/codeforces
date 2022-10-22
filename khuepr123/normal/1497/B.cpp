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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN], m;
bool chk[maxN];
int cnt[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        typre();
        cin >> n >> m;
        ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            
        }
        for(int i = 0; i <= m; i++){
            cnt[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cnt[a[i] % m]++;
        }
        if(cnt[0] > 0) ans = 1;
        if(m % 2 == 1)
        for(int i = 1; i <= m / 2; i++){
            if(cnt[i] > cnt[m - i]) swap(cnt[i], cnt[m - i]);
            if(cnt[i] > 0)
            ans ++;
            cnt[m - i] -= cnt[i];
            if(cnt[m - i] > 0 && cnt[i] > 0) cnt[m - i]--;
            ans += cnt[m - i];
        }
        else{
            for(int i = 1; i < m / 2; i++){
            if(cnt[i] > cnt[m - i]) swap(cnt[i], cnt[m - i]);
            if(cnt[i] > 0)
            ans ++;
            cnt[m - i] -= cnt[i];
            if(cnt[m - i] > 0 && cnt[i] > 0) cnt[m - i]--;
            ans += cnt[m - i];
            }
            if(cnt[m / 2] > 0) ans++;
        }
        cout << ans << endl;
    }
}