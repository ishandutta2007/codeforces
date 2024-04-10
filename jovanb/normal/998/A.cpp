#include <bits/stdc++.h>
using namespace std;

pair <int, int> niz[100000];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i].first;
        niz[i].second = i;
    }
    if(n == 1){cout << -1; return 0;}
    if(n == 2 && niz[1].first == niz[2].first){cout << -1; return 0;}
    sort(niz+1, niz+1+n);
    reverse(niz+1, niz+1+n);
    cout << n-1 << "\n";
    for(int i=1; i<n; i++){
        cout << niz[i].second << " ";
    }
    return 0;
}