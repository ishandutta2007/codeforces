#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector <int> generate_gray(int n){
    if(n == 0) return {0, 1};
    vector <int> a = generate_gray(n - 1);
    vector <int> b = a;
    reverse(b.begin(), b.end());
    for(auto c : b) a.push_back(c ^ (1 << n));
    return a;
}

int gde[32];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    vector <int> gray = generate_gray(4);
    for(int i=0; i<32; i++) gde[gray[i]] = i;
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            int k = (gray[j] ^ gray[j+1]);
            int r = 0;
            for(int t=0; t<5; t++){
                if((1 << t) & k) r += (1 << (2*t));
            }
            cout << r << " ";
        }
        cout << endl;
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            int k = (gray[i] ^ gray[i+1]);
            int r = 0;
            for(int t=0; t<5; t++){
                if((1 << t) & k) r += (1 << (2*t+1));
            }
            cout << r << " ";
        }
        cout << endl;
    }
    int last = 0;
    while(k--){
        int x;
        cin >> x;
        x ^= last;
        int row = 0, col = 0;
        for(int i=0; i<5; i++){
            if(x & (1 << (2*i))) col += (1 << i);
            if(x & (1 << (2*i+1))) row += (1 << i);
        }
        cout << gde[row] + 1 << " " << gde[col] + 1 << endl;
        last = x;
    }
    return 0;
}