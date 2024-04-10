#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main(){
    int t; cin >> t;
    while(t--){
        vector<int> a(4); for(int i=0; i<4; i++) cin >> a[i];
        sort(all(a));
        cout << a[0] * a[2] << "\n";
    }
}