#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;


ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    int p = 0, ans = 1;
    for (int i = 1; i <= n; i++){
        int x, y = 0;
        for (int j = 1; j <= 4; j++){
            cin >> x;
            y += x;
        }
        if (i == 1) p = y;
        else ans += y > p;
    }
    cout << ans << endl;
    return 0;
}