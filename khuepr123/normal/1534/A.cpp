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
int n;
int x, y, z, k;
int m;
char a[55][55];
map<int, char> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    mp[0] = 'R';
    mp[1] = 'W';
    while(o--){
        cin >> n >> m;
        for1(i, 1, n){
            for1(j, 1, m){
                cin >> a[i][j];
            }
        }
        bool killed = 0;
        for1(i, 1, n){
            for1(j, 1, m){
                if(a[i][j] != '.'){
                    for1(ig, 1, n){
                        for1(jg, 1, m){
                            int f1 = (i - ig) & 1;
                            int f2 = (j - jg) & 1;
                            f1 ^= f2;
                            char fk;
                            if(f1){
                                fk = 'W' - a[i][j] + 'R';
                            }
                            else fk = a[i][j];
                            if(a[ig][jg] == '.') a[ig][jg] = fk;
                            else{
                                if(a[ig][jg] != fk) killed = 1;
                            }
                        }
                    }
                    break;
                }
            }
        }
        if(killed) cout << "NO\n";
        else{
            cout << "YES\n";
            for1(i, 1, n){
            for1(j, 1, m){
                if(a[i][j] == '.') a[i][j] = mp[(i ^ j) & 1];
                cout << a[i][j];
            }
            cout << endl;
        }
        }
    }
}