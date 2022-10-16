#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > 0) {
                arr[j]--;
                arr[n - 1]++;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    cin >> t;
    
    while(t--) solve();
    return 0;
}