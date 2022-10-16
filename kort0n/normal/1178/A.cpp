#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll A[105];
ll sum = 0;
ll Asum = 0;
vector<int> ans;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    ans.push_back(1);
    Asum += A[1];
    for(int i = 2; i <= N; i++) {
        if(A[i] * 2 > A[1]) continue;
        ans.push_back(i);
        Asum += A[i];
    }
    if(Asum * 2 <= sum) {
        cout << 0 << endl;
    } else {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}