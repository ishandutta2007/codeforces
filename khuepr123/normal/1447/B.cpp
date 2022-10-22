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
int n, m, a[150][150];
vector<int> tf;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; int sum;
    while(o--){
        tf.clear(); sum = 0;
        cin >> n >> m; bool power = 0; int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                if(a[i][j] == 0){
                    power = 1;
                }
                else if(a[i][j] < 0){
                    cnt++; a[i][j] = 0 - a[i][j];
                }
                tf.pb(a[i][j]); sum += a[i][j];
            }
        }
        if(power || ((cnt + 1) % 2)){
            cout << sum << endl; continue;
        }
        sort(tf.begin(), tf.end());
        cout << sum - tf[0] * 2 << endl;
    }
}