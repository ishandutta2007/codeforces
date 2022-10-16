#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e12;
//const ll mod = 1000000007;

vector<l_l> come[105000], back[105000];
ll N, M, K;
ll ans = INF;
vector<ll> delta[2010000];
ll nowans = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        ll d, f, t, c;
        cin >> d >> f >> t >> c;
        if(f == 0) chmax(d, K + 2);
        if(t == 0) come[f].push_back({d, c});
        else back[t].push_back({d, c});
    }
    for(int i = 1; i <= N; i++) {
        come[i].push_back({-INF, INF});
        sort(come[i].begin(), come[i].end());
        vector<l_l> v;
        for(auto tmp : come[i]) {
            //cerr << i << " " << tmp.first << " " << tmp.second << endl;
            if(v.empty() or v.back().second > tmp.second) {
                v.push_back(tmp);
                //cerr << tmp.first << " " << tmp.second << endl;
            }
        }
        nowans += INF;
        for(int j = 1; j < v.size(); j++) {
            delta[v[j].first+1].push_back(v[j].second - v[j-1].second);
            //cerr << v[j].first << " " << v[j].second - v[j-1].second << endl;
        }
    }
    for(int i = 1; i <= N; i++) {
        back[i].push_back({INF, INF});
        sort(back[i].begin(), back[i].end());
        vector<l_l> v;
        for(auto tmp : back[i]) {
            //cerr << i << " " << tmp.first << " " << tmp.second << endl;
            while(v.size() and v.back().second > tmp.second) {
                v.pop_back();
                //cerr << tmp.first << " " << tmp.second << endl;
            }
            v.push_back(tmp);
        }
        nowans += v[0].second;
        for(int j = 0; j + 1 < v.size(); j++) {
            delta[v[j].first - K + 1].push_back(v[j+1].second - v[j].second);
            //cerr << v[j].first -K + 1 << " " << v[j+1].second - v[j].second << endl;
        }
    }
    for(int day = 0; day <= 2e6; day++) {
        for(auto d : delta[day]) {
            nowans += d;
        }
        chmin(ans, nowans);
        //if(day <= 10) cerr << day << " " << nowans << endl;
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}