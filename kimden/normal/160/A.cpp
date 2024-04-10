#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a;
    int sum = 0;
    vector<int> v;
    for(int i = 0; i < n; ++i){
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.rbegin(), v.rend());
    a = 0;
    int i;
    for(i = 0; i < n; i++){
        a += v[i];
        if(a * 2 > sum){
            break;
        }
    }
    cout << i+1;
    return 0;
}