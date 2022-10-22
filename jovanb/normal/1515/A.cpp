#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[100005];
void solve(){
    int n, x;
    cin >> n >> x;
    int mesto = 0;
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
        if(sum == x){
            if(i == n){
                cout << "NO\n";
                return;
            }
            mesto = i;
        }
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        if(i == mesto){
            cout << a[i+1] << " " << a[i] << " ";
            i++;
            continue;
        }
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}