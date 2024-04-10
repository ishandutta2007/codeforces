#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, c[3];
string a;

void solve(){
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; ++i) c[a[i] - '0']++;
    int nn = n / 3;
    if (c[0] < nn){
        for (int i = 0; i < n && c[0] < nn; ++i){
             if (c[a[i]-'0'] > nn){
                 c[a[i]-'0']--;
                 c[0]++;
                 a[i] = '0';
             }
        }
    }
 
    if (c[2] < nn){
        for (int i = n-1; i >= 0 && c[2] < nn; i--){
             if (c[a[i]-'0'] > nn){
                 c[a[i]-'0']--;
                 c[2]++;
                 a[i] = '2';
             }
        }
    }
 
    if (c[1] < nn){
        for (int i = 0; i < n && c[1] < nn; ++i)
             if (a[i] == '2' && c[2] > nn){
                 a[i] = '1';
                 c[2]--;
                 c[1]++;
             }
 
        for (int i = n-1; i >= 0 && c[1] < nn; i--){
             if (a[i] == '0' && c[0] > nn){
                 a[i] = '1';
                 c[0]--;
                 c[1]++;
             }
        }
    }
    //memset(c, 0, sizeof(c));
    cout << a << "\n";
}

int main(){
    IOS;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}