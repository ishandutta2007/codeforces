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
int n, a[maxN];
bool chk[maxN];
int mx[maxN];
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mx[i] = max(mx[i - 1], a[i]);
        }
        int r = n;
        for(int i = n; i > 0; i--){
            if(a[i] == mx[r]){
                for(int j = i; j <= r; j++){
                    cout << a[j] << " ";
                }
                r = i - 1;
            }
            
        }
        cout << endl;
    }
}