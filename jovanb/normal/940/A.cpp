#include <bits/stdc++.h>
using namespace std;

int niz[1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, d, maxlen = 1;
    cin >> n >> d;
    for(int i=0; i<n; i++){
        cin >> niz[i];
    }
    sort(niz, niz+n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(niz[j]-niz[i] <= d) maxlen = max(maxlen, j-i+1);
        }
    }
    cout << n-maxlen;
    return 0;
}