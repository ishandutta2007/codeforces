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
int N;
vector<l_l> v;
ll graph[200100];
ll SIZE;
vector<l_l> ans;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        l_l now;
        cin >> now.first;
        now.second = i;
        v.push_back(now);
    }
    sort(v.begin(), v.end(), greater<l_l>());
    for(int i = 1; i <= N; i++) {
        graph[i] = v[i-1].second * 2 - 1;
    }
    for(int i = 1; i < N; i++) {
        ans.push_back({graph[i], graph[i+1]});
    }
    SIZE = N;
    for(int i = 0; i < N; i++) {
        int tmp = i + 1 + v[i].first - 1;
        //cerr << i << " " << tmp << " " << SIZE << endl;
        if(SIZE > tmp) {
            ans.emplace_back(graph[tmp], v[i].second * 2);
        } else {
            SIZE++;
            graph[SIZE] = v[i].second * 2;
            ans.emplace_back(graph[SIZE], graph[SIZE-1]);
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " "<< ans[i].second << "\n";
    }
    return 0;
}