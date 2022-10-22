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
int n; int a[maxN]; bool chk[maxN];

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

bool r1[maxN], r0[maxN];
bool l1[maxN], l0[maxN];
int q, x, y;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> q; char c;
        for(int i = 1; i <= n; i++){
            cin >> c;
            if(c == '0') a[i] = 0;
            else a[i] = 1;
        }
        while(q--){
            cin >> x >> y;
            if(x > y) swap(x, y);
            bool chk = 0;
            for(int i = 1; i < x; i++){
                if(a[i] == a[x]) chk = 1;
            }
            for(int i = y + 1; i <= n; i++){
                if(a[i] == a[y]) chk = 1;
            }
            if(chk) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
}