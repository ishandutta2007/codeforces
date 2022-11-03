#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    int n, k;
    cin >> k >> n;
    vector<int> a(k), b(n);
    for(int i = 0; i < k; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 1; i < k; ++i){
        a[i] += a[i - 1];
    }
    set<int> st;
    for(int i = 0; i < k; ++i){
        st.insert(a[i]);
    }
    set<int> st2;
    for(int i = 0; i < k; ++i){
        int pts = b[0] - a[i];
        bool ans = true;
        for(int j = 1; j < n; ++j){
            if(st.count(b[j] - b[0] + a[i]) == 0){
                ans = false;
                break;
            }
        }
        if(ans){
            st2.insert(pts);
        }
    }
    cout << st2.size() << endl;


    return 0;
}