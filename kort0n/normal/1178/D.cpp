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
bool isPrime[10100];
vector<int> primes;
vector<i_i> ans;
int degree[1005];

int main() {
    //cout.precision(10);
    for(int i = 2; i <= 1e4; i++) isPrime[i] = true;
    for(int i = 2; i <= 1e4; i++) {
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j = 2 * i; j <= 1e4; j+= i) isPrime[j] = false;
    }
    /*
    for(int i = 0; i + 1 < primes.size(); i++) {
        if(primes[i] * 3  - 10 <= primes[i+1] * 2) cerr << primes[i] << " " << primes[i+1] << endl;
    }
    */
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) ans.emplace_back(i, i + 1);
    ans.emplace_back(1, n);
    for(int i = 1; i <= n; i++) degree[i] = 2;
    int index = 1;
    while(!isPrime[ans.size()]) {
        while(degree[index] == 3) index++;
        ans.emplace_back(index, index + 2);
        degree[index]++;
        degree[index+2]++;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}