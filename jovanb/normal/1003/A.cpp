#include <bits/stdc++.h>
using namespace std;

int br[105];

int main(){

    int n;
    cin >> n;
    int maxi=0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        br[x]++;
        maxi = max(maxi, br[x]);
    }
    cout << maxi;
    return 0;
}