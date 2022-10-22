#include <bits/stdc++.h>
using namespace std;

int niz[100000];
int mini[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i=0; i<k; i++) cin >> niz[i];
        for(int i=1; i<=n; i++){
            mini[i] = 100000;
            for(int j=0; j<k; j++){
                mini[i] = min(abs(niz[j]-i), mini[i]);
            }
        }
        int minim=mini[1];
        for(int i=1; i<=n; i++)minim = max(minim, mini[i]);
        cout << minim+1<< "\n";
    }
    return 0;
}