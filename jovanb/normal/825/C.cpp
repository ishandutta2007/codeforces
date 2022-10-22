#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    sort(niz+1, niz+1+n);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        while(2*k < niz[i]){
            k *= 2;
            cnt++;
        }
        k = max(k, niz[i]);
    }
    cout << cnt;
    return 0;
}