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
int n, k;
string s;
bool lck;

int a[maxN];
int cnt[27];
int res = 0;
// int rs;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k >> s;
        s = "#" + s;
        for(int i = 0; i < 27; i++) cnt[i] = 0;
        for(int i = 1; i <= n; i++){
            a[i] = s[i] - 'a';
        }
        if(n % k != 0){
            cout << "-1\n"; continue;
        }
        for(int i = n; i > 0; i--){
            cnt[a[i]]++;
        }
        for(int i = n; i > 0; i--){
            lck = 0;
            if(i != n){
                cnt[a[i]]--;
                a[i]++;
                cnt[a[i]]++;
            }
            while(a[i] != 26){
                res = 0;
                for(int j = 0; j < 26; j++){
                    if(cnt[j] % k != 0) res += (k - (cnt[j] % k));
                }
                // if(o == 0) cout << endl << res << endl;
                if(res <= n - i){
                    res = (n - i) - res;
                    for(int j = 1; j <= i; j++) cout << char(a[j] + 'a');
                    while(res--) cout << 'a';
                    for(int j = 0; j < 26; j++){
                        if(cnt[j] % k != 0){
                            for(int f = 0; f < (k - (cnt[j] % k)); f++)
                            cout << char(j + 'a');
                        }
                    }
                    cout << endl;
                    lck = 1;
                    break;
                }
                cnt[a[i]]--;
                a[i]++;
                cnt[a[i]]++;
                // for(int j = 1; j <= n; j++) cout << char(a[j] + 'a');
                // cout << endl;
            }
            if(lck) break;
        }
    }
}