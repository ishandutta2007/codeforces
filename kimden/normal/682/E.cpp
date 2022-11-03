#include <bits/stdc++.h>
#pragma optimize("Ofast")
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct pt {
    int x = 0, y = 0;
    bool operator < (const pt& rhs)const {
        if(x == rhs.x){
            return y < rhs.y;
        }
        return x < rhs.x;
    }
    bool bad(const pt& b, const pt& c)const {
        return (b.x - x) * ll(c.y - y) >= (b.y - y) * ll (c.x - x);
    }
    ll area2(const pt& b, const pt& c)const {
        return abs((b.x - x) * ll(c.y - y) - (b.y - y) * ll (c.x - x));
    }
    pt operator + (const pt& rhs)const {
        pt p;
        p.x = x + rhs.x;
        p.y = y + rhs.y;
        return p;
    }
    pt operator - (const pt& rhs)const {
        pt p;
        p.x = x - rhs.x;
        p.y = y - rhs.y;
        return p;
    }
};

int n;

inline void inc(int& x){
    ++x;
    if(x == n){
        x = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll s;
    cin >> n >> s;
//    n = 5000;
    vector<pt> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].y;
//        if(i == 0){
//            a[i].x = 0;
//            a[i].y = 0;
//        }else{
//            a[i].x = a[i - 1].x + 1;
//            a[i].y = a[i - 1].y + i;
//        }
    }
    sort(all(a));
    vector<pt> b, c;
    for(int i = 0; i < n; ++i){
        while(b.size() > 1 && b[b.size() - 2].bad(b.back(), a[i])){
            b.pop_back();
        }
        b.push_back(a[i]);
    }
    for(int i = n - 1; i >= 0; --i){
        while(c.size() > 1 && c[c.size() - 2].bad(c.back(), a[i])){
            c.pop_back();
        }
        c.push_back(a[i]);
    }
    b.pop_back();
    c.pop_back();
    for(auto p: c){
        b.push_back(p);
    }
    n = b.size();
    pair<ll, vector<int>> ans = {-1, {}};
    for(int i = 0; i < n; ++i){
        int i1 = (i ? i - 1 : n - 1);
        int j = i;
        inc(j);
        int k = j;
        inc(k);
        while(j != i1){
            ll z = b[i].area2(b[j], b[k]);
            while(k != i1){
                int p = k;
                inc(p);
                ll o = b[i].area2(b[j], b[p]);
                if(z >= o){
                    break;
                }
                z = o;
                k = p;
            }
            ans = max(ans, {b[i].area2(b[j], b[k]), {i, j, k}});
            inc(j);
            if(j == k){
                inc(k);
            }
        }
    }
    pt A = b[ans.second[0]] + b[ans.second[1]] - b[ans.second[2]];
    pt B = b[ans.second[1]] + b[ans.second[2]] - b[ans.second[0]];
    pt C = b[ans.second[2]] + b[ans.second[0]] - b[ans.second[1]];
    cout << A.x << " " << A.y << "\n";
    cout << B.x << " " << B.y << "\n";
    cout << C.x << " " << C.y << "\n";
}