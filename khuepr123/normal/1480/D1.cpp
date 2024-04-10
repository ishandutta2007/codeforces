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
int ans;
 
int cnt;
int amount[maxN];
int number[maxN];
int x;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cnt = 0;
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n + 1] = -1;
    a[0] = -1;
    for(int i = 1; i <= n; i++){
        if(a[i] != a[i + 1]){
            cnt++;
            number[cnt] = a[i];
            amount[cnt] = 1;
            if(a[i] == a[i - 1])
            amount[cnt] = 2;
        }
    }
    n = cnt;
    for(int i = 1; i <= n; i++){
        ans += amount[i];
    }
    
    int l = 0;
    int r = n + 1;
    while(++l){
        if(l == n + 1){
            cout << ans; return 0;
        }
        if(amount[l] == 2) break;
    }
    while(--r){
        if(amount[r] == 2) break;
    }
    while(l != r){
        int rig = l;
        while(++rig){
            if(amount[rig] == 2) break;
        }
        if(number[rig] != number[l]){
            l = rig; continue;
        }
        int pad = 1;
        for(int i = l + 1; i < rig; i++){
            if(number[i + 1] != number[i - 1] && number[i] != number[l])
            pad = 0;
        }
        ans -= pad;
        l = rig;
    }
    cout << ans << endl;
}