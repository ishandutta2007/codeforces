// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

int main(){
    iostream_init();
    deque<int> A;
    deque<int> B;
    int N;
    cin >> N;
    int K;
    cin >> K;
    REP(i, K) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cin >> K;
    REP(i, K) {
        int x;
        cin >> x;
        B.push_back(x);
    }
    set<vector<int>> st[11];
    int answer = 0;
    while(true) {
        int k = A.size();
        if(A.empty()) {
            cout << answer << " " << 2 << endl;
            break;
        }
        if(B.empty()) {
            cout << answer << " " << 1 << endl;
            break;
        }

        vector<int> state(A.begin(), A.end());
        state.insert(state.end(), B.begin(), B.end());
        if(st[k].count(state)){ cout << -1 << endl; break; }
        st[k].insert(state);

        answer++;
        if(A.front() < B.front()) {
            int a = A.front();
            int b = B.front();
            A.pop_front();
            B.pop_front();
            B.push_back(a);
            B.push_back(b);
        } else {
            int a = A.front();
            int b = B.front();
            A.pop_front();
            B.pop_front();
            A.push_back(b);
            A.push_back(a);
        }
    }
    return 0;
}

/* vim:set foldmethod=marker: */