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
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}

int x, y;

int cnt1;

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    int o; cin >> o;
    cnt1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]) cnt1++;
    }
    while(o--){
        cin >> x >> y;
        if(x == 1){
            if(a[y] == 0) cnt1++;
            else cnt1--;
            a[y] = 1 - a[y];
        }
        else{
            if(cnt1 >= y) cout << "1\n";
            else cout << "0\n";
        }
    }
}