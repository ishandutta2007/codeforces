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
 
struct query {
    int index;
    long double s, r;
    query(int _index, int _s, int _r) {
        index = _index;
        s = _s;
        r = _r;
    }
    query() {
        index = 0;
        s = 0;
        r = 0;
    }
};
 
const long double EPS = 1e-10;
 
bool operator>(query a, query b) {
    if(abs(a.s - b.s) > EPS) return a.s > b.s;
    if(abs(a.r - b.r) > EPS) return a.r > b.r;
    return a.index > b.index;
}
 
bool operator<(query a, query b) {
    if(abs(a.s - b.s) > EPS) return a.s < b.s;
    if(abs(a.r - b.r) > EPS) return a.r < b.r;
    return a.index < b.index;
}
 
int N;
 
bool win(query a, query b, long double R) {
    long double ascore = 1 / a.s + R / a.r;
    long double bscore = 1 / b.s + R / b.r;
    /*
    cerr << a.index << " vs " << b.index << endl;
    cerr << ascore << " " << bscore << endl;
    */
    return ascore - bscore <= EPS;
}
 
long double getR(query a, query b, long double minimum) {
    long double ok = 1e18;
    long double ng = minimum;
    for(int timer = 0; timer <= 500; timer++) {
        long double mid = (ok + ng) / 2.0;
        if(win(a, b, mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}
 
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<query> input(N);
    for(int i = 1; i <= N; i++) {
        int r, s;
        cin >> s >> r;
        input[i-1].index = i;
        input[i-1].s = s;
        input[i-1].r = r;
    }
    sort(input.begin(), input.end(), greater<query>());
    vector<query> candidate;
    long double rmax = 0.0;
    long double rmaxbefore = 0.0;
    for(int i = 0; i < input.size(); i++) {
        if(i >= 1 && input[i-1].s - input[i].s > EPS) rmaxbefore = rmax;
        //cerr << i << " " << rmaxbefore << " " << rmax << endl;
        if(rmax - input[i].r >= EPS) continue;
        chmax(rmax, input[i].r);
        if(!(input[i].r - rmaxbefore >= EPS)) continue;
        candidate.push_back(input[i]);
    }
    for(int i = 0; i < candidate.size(); i++) cerr << candidate[i].index << endl;
    vector<pair<query, long double> > v;
    v.push_back({candidate[0], 0.0});
    for(int i = 1; i < candidate.size(); i++) {
        while(!v.empty()) {
            if(!win(v.back().first, candidate[i], v.back().second)) {
                //cerr << candidate[i].index << " wins against " << v.back().first.index << endl;
                v.pop_back();
            } else {
                break;
            }
        }
        long double minimum = getR(candidate[i], v.back().first, v.back().second);
        cerr << candidate[i].index << " wins against " << v.back().first.index << " with R=" << minimum << endl;
        v.push_back({candidate[i], minimum});
    }
    vector<int> ans;
    for(int i = 0; i < v.size(); i++) {
        ans.push_back(v[i].first.index);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}