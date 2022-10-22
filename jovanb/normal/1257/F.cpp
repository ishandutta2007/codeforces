#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <vector <int>, int> ima;
int a[105];

int uradi(int x, int l, int r){
    int res = 0;
    for(int j=l; j<r; j++){
        if((1<<j) & x) res++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int mask=0; mask<(1<<15); mask++){
        vector <int> vc;
        int x = uradi(a[1] ^ mask, 0, 15);
        for(int i=2; i<=n; i++){
            vc.push_back(uradi(a[i] ^ mask, 0, 15) - x);
        }
        if(!ima[vc]) ima[vc] = mask+1;
    }
    for(int mask=0; mask<(1<<15); mask++){
        int dmask = (1<<15)*mask;
        vector <int> vc;
        int x = uradi(a[1] ^ dmask, 15, 30);
        for(int i=2; i<=n; i++){
            vc.push_back(-uradi(a[i] ^ dmask, 15, 30) + x);
        }
        if(ima[vc]){
            cout << (dmask ^ (ima[vc] - 1)) << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}