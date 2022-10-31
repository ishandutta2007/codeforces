// Hydro submission #62220cf68331ffa528ce9092@1646398710702
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 10100, M = 500100;

int a[100100], b[100100];

void solve(){
    int n, k; cin >> n >> k;
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        sum1 += a[i]; sum2 += b[i];
    }
    if(k >= sum1 && k <= sum2){
        cout << "YES" << '\n';
        int cnt = k - sum1;
        for(int i = 1; i <= n; i++){
            if(cnt >= b[i] - a[i]){
                cout << b[i] << ' ';
                cnt -= b[i] - a[i];
            } else {
                cout << a[i] + cnt << ' ';
                cnt = 0;
            }
        }
    } else cout << "NO";


}



int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
}