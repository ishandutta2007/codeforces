#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int res[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m, q;
    cin >> n >> m >> q;
    string a, b;
    cin >> a >> b;
    for(int i=0; i+m<=n; i++){
        for(int j=i; j<i+m; j++){
            if(a[j] != b[j-i]) break;
            if(j == i+m-1){
                res[i+1] = 1;
            }
        }
    }
    for(int i=1; i<=n; i++) res[i] += res[i-1];
    while(q--){
        int x, y;
        cin >> x >> y;
        y = y-m+1;
        if(y < x) cout << "0\n";
        else cout << res[y]-res[x-1] << "\n";
    }
    return 0;
}