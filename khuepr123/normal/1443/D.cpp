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
int l[maxN]; int r[maxN];

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}

// l    5 4 3 2 1 phot
// r    1 2 3 4 5 phot

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i]; l[i] = 0; r[i] = 0;
        }
        l[1] = a[1]; r[1] = 0; int sum;
        for(int i = 2; i <= n; i++){
            sum = a[i - 1];
            if(a[i] == sum){
                l[i] = l[i - 1]; r[i] = r[i - 1];
            }
            else if(a[i] > sum){
                l[i] = l[i - 1]; r[i] = a[i] - l[i];
            } 
            else if(a[i] < sum){
                r[i] = r[i - 1]; l[i] = a[i] - r[i];
            }
        }
        if(l[n] < 0) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}