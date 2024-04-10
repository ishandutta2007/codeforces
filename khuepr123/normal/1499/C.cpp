#include<bits/stdc++.h>
using namespace std;

#define int long long
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
int n, a[maxN], b[maxN];
int ca, cb;
int pra[maxN];
int prb[maxN];
int mna[maxN];
int mnb[maxN];
int ans;

int solve(int ff1, int ff2){
    // cout << ff1 << ff2 << endl << endl;
    
    // if(ff1 == 1 && ff2 == 1){
    //     cout << pra[ff1] << " ";
    //     cout << prb[ff2] << " ";
    //     cout << n - ff1 << " ";
    //     cout << mnb[ff1] << " ";
    //     cout << n - ff2 << " ";
    //     cout << mnb[ff2] << " ";
        
    // }
    return pra[ff1] + prb[ff2] + (n - ff1) * mna[ff1] + (n - ff2) * mnb[ff2];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        ca = 0;
        cb = 0;
        for(int i = 1; i <= n; i++){
            if(i % 2 == 1) cin >> a[++ca];
            if(i % 2 == 0) cin >> b[++cb];
            
        }
        // sort(a + 1, a + ca + 1);
        // sort(b + 1, b + cb + 1);
        pra[0] = 0;
        prb[0] = 0;
        mna[0] = oo;
        mnb[0] = oo;
        for(int i = 1; i <= ca; i++){
            pra[i] = pra[i - 1] + a[i];
            mna[i] = min(mna[i - 1], a[i]);
            // cout << mna[i] << " ";
        }
        // cout << endl;
        for(int i = 1; i <= cb; i++){
            prb[i] = prb[i - 1] + b[i];
            mnb[i] = min(mnb[i - 1], b[i]);
            // cout << mnb[i] << " ";
        }
        // cout << endl;
        ans = oo;
        int ff1 = 0;
        int ff2 = 0;
        while(1){
            ff1++;
            if(ff1 > 0 && ff2 > 0) ans = min(ans, solve(ff1, ff2));
            if(ff1 + ff2 == n) break;
            ff2++;
            if(ff1 > 0 && ff2 > 0) ans = min(ans, solve(ff1, ff2));
            // if(o == 2) // cout << ff1 << ff2 << endl;
            if(ff1 + ff2 == n) break;
        }
        cout << ans << endl;
    }
}