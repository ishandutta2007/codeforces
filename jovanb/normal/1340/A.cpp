#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int a[100005];
int pos[100005];

bool solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    int tren = 1;
    int r = n+1;
    while(tren < n){
        //cout << tren << endl;
        int l = pos[tren];
        for(int i=l+1; i<r; i++){
            tren++;
            if(pos[tren] !=  i) return 0;
        }
        tren++;
        r = l;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}