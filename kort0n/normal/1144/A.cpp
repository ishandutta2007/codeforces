#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        set<char> st;
        bool flag = true;
        for(int i = 0; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) {
                cout << "No" << endl;
                flag = false;
                break;
            }
            st.insert(s[i]);
            if(i > 0) {
                if(s[i] - s[i - 1] != 1) {
                    cout << "No" << endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout << "Yes" << endl;
    }
    return 0;
}