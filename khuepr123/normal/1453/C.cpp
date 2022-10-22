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
int n; char c; int a[2005][2005];
int tmp[2005][2005]; int mx;
int cnt; int pos;
int l, r;
int rail[2005];
int close[2005];
int low;
int cnt2;
int mxdig[15];

void process(){
    for(int dig = 0; dig < 10; dig++){
        mx = 0;
        cnt2 = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] == dig) cnt2++;
            }
        }
        if(cnt2 < 2){
            continue;
        }
        low = 0;
        for(int i = n; i > 0; i--){
            for(int j = 1; j <= n; j++){
                if(a[i][j] == dig){
                    low = i; break;
                }
            }
            if(low != 0) break;
        }
        for(int i = 1; i <= n; i++){
            // here
            cnt2 = 0;
            for(int j = 1; j <= n; j++){
                if(a[i][j] == dig) cnt2++;
            }
            if(cnt2 < 1){
                rail[i] = 0; close[i] = 0; continue;
            }
            for(int j = 1; j <= n; j++){
                if(a[i][j] == dig){
                    l = j; break;
                }
            }
            for(int j = n; j > 0; j--){
                if(a[i][j] == dig){
                    r = j; break;
                }
            }
            close[i] = max(r - 1, n - l);
            rail[i] = r - l;
            // end
        }
        for(int i = 1; i <= n; i++){
            mx = max({mx, close[i] * (low - i), rail[i] * (n - i)});
        }
        mxdig[dig] = max(mx, mxdig[dig]);
    }
    
}

void cope(){
    pos = -1;
    for(int i = 1; i <= n; i++){
        for(int j = n; j > 0; j--){
            pos++;
            tmp[i][j] = a[(pos % n) + 1][pos / n + 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = tmp[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
        }
    }
    process();
}

signed main(){
    ios_base::sync_with_stdio(0);
    // 10 digit :v
    // distance from all edge
    // maximum length in the line, calc sum on the go
    int o; cin >> o;
    while(o--){
        for(int i = 0; i < 15; i++){
            mxdig[i] = 0;
        }
        cin >> n; mx = 0; cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> c;
                a[i][j] = c - 48;
            }
        }
        process();
        cope();
        cope();
        cope();
        for(int i = 0; i < 10; i++){
            cout << mxdig[i] << " ";
        }
        cout << endl;
    }
}