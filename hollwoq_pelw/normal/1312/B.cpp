#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n, greater<int>());
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}