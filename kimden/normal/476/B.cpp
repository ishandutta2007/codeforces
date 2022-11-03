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
    string s, t;
    cin >> s;
    cin >> t;
    int q = 0, offset = 0;
    for(int i = 0; i < s.length(); ++i){
        offset += (s[i] == '+' ? 1 : -1);
    }
    for(int i = 0; i < t.length(); ++i){
        if(t[i] == '?'){
            q++;
        }else {
            offset -= (t[i] == '+' ? 1 : -1);
        }
    }
    if((q + abs(offset)) % 2 != 0){
        cout << setprecision(12) << fixed << 0 << endl;
        return 0;
    }
    ld ans = 1;
    int n = q;
    int k = (offset + n) / 2;
    if(k > n || k < 0){
        cout << setprecision(12) << fixed << 0 << endl;
        return 0;
    }
    k = min(k, n - k);
    for(int i = 0; i < k; ++i){
        ans = ans * 1. * (n - i) / (i + 1);
    }
    ans /= (1 << n);
    cout << setprecision(12) << fixed << ans << endl;

}