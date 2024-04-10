#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int niz1[100009];
int niz2[100009];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    for(int i=1; i<=n; i++){
        cin >> niz1[i];
    }
    for(int i=1; i<=m; i++){
        cin >> niz2[i];
    }
    sort(niz1+1, niz1+1+n);
    reverse(niz1+1, niz1+1+n);
    sort(niz2+1, niz2+1+m);
    reverse(niz2+1, niz2+1+m);
    for(int i=1; i<=min(m, n); i++){
        if(niz1[i] > niz2[i]){cout << "YES"; return 0;}
    }
    if(n > m) cout << "YES";
    else cout << "NO";
    return 0;
}