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
int n, a[maxN];
bool chk[maxN];
int health;
int power;

int p[maxN];
int h[maxN];

bool lck;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        lck = 1;
        cin >> power >> health >> n;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> h[i];
            int lame = ((h[i] - 1) / power) + 1;
            health = health - (lame * p[i]);
        }
        for(int i = 1; i <= n; i++){
            if(health + p[i] > 0){
                lck = 0;
                cout << "YES\n";
                break;
            }
        }
        if(lck) cout << "NO\n";
        // cout << health << endl;
    }
}