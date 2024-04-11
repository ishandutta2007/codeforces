#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<l_l, ll> lll;
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
multiset<l_l> s;
multiset<ll> t;
multiset<lll> toleft;
multiset<lll> toright;
vector<lll> ans;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        ll in;
        cin >> in;
        s.insert({in, i});
    }
    for(int i = 1; i <= N; i++) {
        ll in;
        cin >> in;
        t.insert(in);
    }
    auto itrs = s.begin();
    auto itrt = t.begin();
    while(itrs != s.end()) {
        if((*itrs).first > *itrt) {
            toleft.insert({{(*itrs).first, (*itrs).first - *itrt}, (*itrs).second});
            //cerr << "TOLEFT" << endl;
            //cerr << (*itrs).first << " " <<  (*itrs).first - *itrt << " " <<  (*itrs).second << endl;
        } else if((*itrs).first < *itrt) {
            toright.insert({{(*itrs).first, -(*itrs).first + *itrt}, (*itrs).second});
            //cerr << "TORIGHT" << endl;
            //cerr << (*itrs).first << " " <<  -(*itrs).first + *itrt << " " <<  (*itrs).second << endl;
        }
        itrs++;
        itrt++;
    }
    for(auto itr = toright.begin(); itr != toright.end(); itr++) {
        lll rightnow = *itr;
        //cerr << "----NEXT----" << endl;
        //cerr << "SIZE: " << toleft.size() << endl;
        auto itr2 = toleft.begin();
        while(true) {
            if(itr2 == toleft.end()) {
                cout << "NO" << endl;
                return 0;
            }
            lll leftnow = *itr2;
            //cerr << "RIGHT: " << rightnow.first.first << " " << rightnow.first.second << " " << rightnow.second << endl;
            //cerr << "LEFT: " << leftnow.first.first << " " << leftnow.first.second << " " << leftnow.second << endl;
            if(leftnow.first.first < rightnow.first.first) {
                cout << "NO" << endl;
                return 0;
            }
            ll delta = (leftnow.first.first - rightnow.first.first) / 2;
            chmin(delta, rightnow.first.second);
            chmin(delta, leftnow.first.second);
            itr2 = toleft.erase(itr2);
            ans.push_back({{rightnow.second, leftnow.second}, delta});
            //cerr << delta << endl;
            rightnow.first.second -= delta;
            rightnow.first.first + delta;
            leftnow.first.first -= delta;
            leftnow.first.second -= delta;
            if(leftnow.first.second > 0) {
                toleft.insert(leftnow);
                //cerr << "A" << endl;
            }
            if(rightnow.first.second == 0) break;
        }
    }
    if(!toleft.empty()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
    }
    return 0;
}