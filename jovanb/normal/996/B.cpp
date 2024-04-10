#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int mini=1000000000;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        mini = min(mini, niz[i]);
    }
    int k = mini/n;
    for(int i=1; i<=n; i++){
        niz[i] -= k*n;
    }
    int t=0;
    while(1){
        for(int i=1; i<=n; i++){
            if(niz[i]-t <= 0){cout << i; return 0;}
            t++;
        }
    }
    return 0;
}