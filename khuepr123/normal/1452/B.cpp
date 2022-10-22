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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n; int a[maxN]; bool chk[maxN]; int sum;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; sum = 0; int lsum;
    while(o--){
        cin >> n; sum = 0; lsum = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i]; lsum += a[i];
        }
        sort(a + 1, a + n + 1);
        lsum = lsum % (n - 1); lsum = (n - 1) - lsum;
        if(lsum == n - 1) lsum = 0;
        for(int i = 2; i <= n; i++){
            sum = sum + a[n] - a[i];
        }
        int x = 0; int cl = max(x, sum - a[1]);
        while(cl % (n - 1) != lsum) cl++;
        cout << cl << endl;
    }
}