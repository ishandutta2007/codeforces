#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int mxc = 1;
int k;
int edg[1005][1005];

void split(int l, int r, int c){
    if(l >= r) return;
    mxc = max(mxc, c);
    for(int i=l; i<=r; i++){
        for(int j=i+1; j<=r; j++){
            edg[i][j] = c;
        }
    }
    int len = (r-l+1 + k-1)/k;
    for(int i=l; i<=r; i+=len) split(i, min(i+len-1, r), c + 1);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n >> k;
    split(1, n, 1);
    cout << mxc << "\n";
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            cout << edg[i][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}