// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

template<typename T1, typename T2>
ostream& operator << (ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++)
        os << v[i] << (i+1<v.size()?", ":"");
    os << "}";
    return os;
}

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

int time(string s) {
    for(char& c : s) if(c == ':') c = ' ';
    stringstream ss(s);
    int h, m, c;
    ss >> h >> m >> c;
    return 60*60*h + 60*m + c;
}
int main(){
    iostream_init();

    int N, M, T;
    while(cin >> N >> M >> T) {
        vector<int> t(N);
        REP(i, N) {
            string s;
            cin >> s;
            t[i] = time(s);
        }
        // assert(sorted(t))

        vector<int> b, e;
        {
            int last = 0;
            REP(i, N){
                bool update = false;
                while(last < N && t[last] < t[i] + T) {
                    update = true;
                    last++;
                }
                if(update) {
                    // cout << i << " " << last << endl;
                    b.push_back(i);
                    e.push_back(last);
                }
            }
        }

        int L = b.size();
        bool exist = false;
        REP(i, L) if(e[i] - b[i] >= M) exist = true;
        if(!exist) {
            cout << "No solution" << endl;
            continue;
        }

        vector<int> ans(N);
        int last = 0;
        int start = 0;
        vector<int> cnt(L);
        for(int i = 0; i < N; i++) {
            bool add_ok = true;

            // increment for e[start-1] <= i and i < e[start]
            while(start < L && e[start] <= i) start++;
            // cout << "start: " << start << endl;
            // cout << "cnt: " << cnt << endl;

            for(int j = start; j < L; j++) {
                // i < e[start]
                if(i < b[j]) break;
                if(cnt[j] == M) add_ok = false;
            }
            if(add_ok) {
                ans[i] = ++last;
                for(int j = start; j < L; j++) {
                    if(i < b[j]) break;
                    cnt[j]++;
                }
            } else {
                ans[i] = last;
                for(int j = start; j < L; j++) {
                    if(i < b[j]) break;
                    if(b[j] == i) cnt[j]++;
                }
            }
        }
        cout << last << endl;
        REP(i, N) cout << ans[i] << endl;
    }


    return 0;
}

/* vim:set foldmethod=marker: */