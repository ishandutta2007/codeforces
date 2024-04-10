#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int B = 24;
int contain[(1<<B)];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string x;
        cin >> x;
        for(int j=0; j<3; j++){
            contain[1<<(x[j]-'a')]++;
        }
        for(int j=0; j<3; j++){
            for(int k=j+1; k<3; k++){
                contain[(1<<(x[j]-'a')) | (1<<(x[k]-'a'))]--;
            }
        }
        contain[(1<<(x[0]-'a')) | (1<<(x[1]-'a')) | (1<<(x[2]-'a'))]++;
    }
    int res = 0;
    for(int i=0; i<B; i++){
        for(int mask=0; mask<(1<<B); mask++){
            if((1<<i) & mask) contain[mask] += contain[mask ^ (1<<i)];
        }
    }
    for(int i=0; i<(1<<B); i++){
        res ^= contain[i]*contain[i];
    }
    cout << res << "\n";
    return 0;
}