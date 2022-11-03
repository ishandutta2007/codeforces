#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//random_device rd;
//uniform_int_distribution<int> nn(2, 300);
//uniform_int_distribution<int> dist(0, 1000000000);
//      chrono::system_clock::now();
//      chrono::duration_cast<chrono::milliseconds>(finish - start).count()

const ld eps = 1e-10;
int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        v.push_back(a);
    }
    int ans;
    int cur;
    int idx;
    for(int i = 0; i < k; ++i){
        cur += v[i];
    }
    ans = cur;
    idx = 0;
    for(int i = k; i < n; ++i){
        cur += v[i] - v[i - k];
        if(ans > cur){
            ans = cur;
            idx = i - k + 1;
        }
    }
    cout << idx + 1 << endl;

}