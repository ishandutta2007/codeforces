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
int n, a[55][55];
int x, y, z, k;
int cnt[4];

void pour(int rw, int god, int child){
    for1(i, rw, rw + 3){
        for1(j, 1, 50){
            a[i][j] = god;
        }
    }
    for1(i, rw + 1, rw + 2){
        for1(j, 2, 49){
            if(((i + j) % 2) && cnt[child]){
                cnt[child]--; a[i][j] = child;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    for1(i, 0, 3) cin >> cnt[i];
    cnt[2]--;
    cnt[0]--;
    cout << "48 50" << endl;
    for(int i = 1; i <= 12; i += 4){
        pour(i, 0, 3);
    }
    for(int i = 13; i <= 24; i += 4){
        pour(i, 0, 2);
    }
    for(int i = 25; i <= 36; i += 4){
        pour(i, 2, 0);
    }
    for(int i = 37; i <= 48; i += 4){
        pour(i, 2, 1);
    }
    for1(i, 1, 48){
        for1(j, 1, 50){
            cout << char(a[i][j] + 'A');
        }
        cout << endl;
    }
}