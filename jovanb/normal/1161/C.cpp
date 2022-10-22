#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int mn = 50;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        mn = min(mn, niz[i]);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(mn == niz[i]) cnt++;
    }
    if(cnt <= n/2){
        cout << "Alice";
    }
    else cout << "Bob";
    return 0;
}