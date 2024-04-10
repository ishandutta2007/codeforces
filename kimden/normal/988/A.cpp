#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int x;
    vector<int> v(103, 0), w;
    for(int i = 0; i < n; ++i){
        cin >> x;
        v[x] = i + 1;
    }
    for(int i = 0; i < 103; ++i){
        if(v[i]){
            w.push_back(v[i]);
        }
    }
    if(w.size() >= k){
        cout << "YES" << endl;
        for(int i = 0; i < k; ++i){
            if(i){
                cout << " ";
            }
            cout << w[i];
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }


}