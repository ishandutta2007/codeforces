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
const int mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    bool lck = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = mod;
    a[n + 1] = mod;
    for(int i = 1; i <= n; i++){
        if(i != 1 && i != n && (a[i] < a[i - 1] || a[i] < a[i + 1])) continue;
        // cout << i << endl;
        int cnt1 = 0;
        int cnt2 = 0;
        int track = i;
        while(1){
            track--;
            if(a[track] > a[track + 1] || track == 0){
                cnt1 = i - track;
                break;
            }
        }
        track = i;
        while(1){
            track++;
            if(a[track] > a[track - 1] || track == n + 1){
                cnt2 = track - i;
                break;
            }
        }
        if(mx == cnt1 || mx == cnt2) lck = 0;
        else{
            if(cnt1 >= mx || cnt2 >= mx) lck = 0;
            mx = max(mx, cnt1);
            mx = max(mx, cnt2);
            if(cnt1 == cnt2 && mx == cnt1 && (cnt1 % 2 == 1) && mx != 1){
                lck = 1;//  cout << i << endl;
            }
        }
    }
    cout << lck; return 0;
}