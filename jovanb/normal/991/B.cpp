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
    int sum=0;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        sum += niz[i];
    }
    sort(niz+1, niz+1+n);
    int kv = (n*9+1)/2;
    if(sum >= kv){cout << 0; return 0;}
    for(int i=1; i<=n; i++){
        sum += 5-niz[i];
        if(sum >= kv){cout << i; return 0;}
    }
    return 0;
}