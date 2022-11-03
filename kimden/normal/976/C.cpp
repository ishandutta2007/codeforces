#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int l, r;
    map<int, int> mpl, mpr;
    vector<pii> seg;
    vector<pii> ev;
    for(int i = 0; i < n; ++i){
        cin >> l >> r;
        seg.push_back({l, r});
        ev.push_back({l, -i - 1});
        ev.push_back({r, i + 1});
        auto it1 = mpl.find(l);
        auto it2 = mpr.find(r);
        if(it1 != mpl.end()){
            int j = it1->second;
            if(seg[j].second >= seg[i].second){
                cout << i + 1 << " " << j + 1 << endl;
            }else{
                cout << j + 1 << " " << i + 1 << endl;
            }
            return 0;
        }
        if(it2 != mpr.end()){
            int j = it2->second;
            if(seg[j].first <= seg[i].first){
                cout << i + 1 << " " << j + 1 << endl;
            }else{
                cout << j + 1 << " " << i + 1 << endl;
            }
            return 0;
        }
        mpl[l] = i;
        mpr[r] = i;
    }
    sort(all(ev));
    queue<int> q;
    for(int i = 0; i < ev.size(); ++i){
        int type = ev[i].second < 0 ? 1 : 2;
        int who = abs(ev[i].second) - 1;
        if(type == 1){
            q.push(who);
        }else{
            if(q.front() != who){
                cout << who + 1 << " " << q.front() + 1 << endl;
                return 0;
            }
            q.pop();
        }
    }
    cout << "-1 -1" << endl;
}