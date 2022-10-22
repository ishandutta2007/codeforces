#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[100];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, a, b;
    int cost=0;
    cin >> n >> a >> b;
    for(int i=1; i<=n; i++) cin >> niz[i];
    for(int i=1; i<=n; i++){
        int j = n-i+1;
        if(j == i){
            if(niz[i] == 2) cost += min(a, b);
        }
        if(j <= i) break;
        if(niz[i] != 2 && niz[j] != 2){
            if(niz[i] != niz[j]){cout << -1; return 0;}
        }
        else if(niz[i] == 2 && niz[j] == 2){
            cost += 2*min(a, b);
        }
        else if(niz[i] == 2){
            if(niz[j] == 0) cost += a;
            else cost += b;
        }
        else if(niz[j] == 2){
            if(niz[i] == 0) cost +=a;
            else cost += b;
        }
    }
    cout << cost;
    return 0;
}