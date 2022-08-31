#include <bits/stdc++.h>

using i64 = long long;

int n;
int tot;
int query(std::string s) {
    std::cout << s.substr(0, n) << std::endl;
    int res;
    // res = 0;
    // for (int i = 0; i < n; i++) {
    //     res += (s[i] == "TF"[i % 2]);
    // }
    std::cin >> res;
    if (res == n) {
        std::exit(0);
    }
    for (int i = n; i < int(s.length()); i++) {
        res += (s[i] == 'F');
    }
    // std::cerr << res << std::endl;
    return res;
}

std::string flip(std::string s) {
    for (auto &c : s) {
        if (c == 'T') {
            c = 'F';
        } else {
            c = 'T';
        }
    }
    return s;
}

template<int O>
struct Strategy {
    Strategy<O - 1> A, B;
    static const int n = Strategy<O - 1>::n * 2 + Strategy<O - 1>::q;
    static const int q = Strategy<O - 1>::q * 2 + 1;
    std::vector<std::string> qa, qb;
    std::function<void(std::string)> query;
    Strategy() {
        query = [this](std::string s) {
            static auto *obj = this;
            int res = ::query(s);
            res += tot;
            res -= std::count(s.begin(), s.end(), 'F');
            res /= 2;
            obj->receive(res);
        };
        A.query = [this](std::string s) {
            qa.push_back(s);
            if (qa.size() <= qb.size()) {
                doQuery(qa.size() - 1);
            }
        };
        B.query = [this](std::string s) {
            qb.push_back(s);
            if (qb.size() <= qa.size()) {
                doQuery(qb.size() - 1);
            }
        };
    }
    void doQuery(int k) {
        std::string t1 = qa[k] + qb[k] + std::string(Strategy<O - 1>::q, 'F');
        std::string t2 = qa[k] + flip(qb[k]) + std::string(Strategy<O - 1>::q, 'F');
        t1[Strategy<O - 1>::n * 2 + k] = 'T';
        query(t1);
        query(t2);
    }
    std::string ans;
    int s = -1;
    int k = 0;
    int last = -1;
    void receive(int res) {
        // std::cerr << "receive(" << O << ", " << res << ")\n";
        // std::cerr << "res : " << res << "\n";
        if (s == -1) {
            s = res;
        } else if (last == -1) {
            last = res;
        } else {
            A.receive((last + res - s) / 2);
            B.receive((last - res + s) / 2);
            // std::cerr << last << " " << res << "\n";
            ans += "FT"[(last + res - s) % 2];
            // std::cerr << "ans : " << ans << "\n";
            k++;
            last = -1;
        }
    }
    void solve() {
        query(std::string(Strategy<O - 1>::n, 'F') + std::string(Strategy<O - 1>::n, 'T') + std::string(Strategy<O - 1>::q, 'F'));
        A.solve();
        B.solve();
    }
    std::string answer() {
        return A.answer() + B.answer() + ans;
    }
};

template<>
struct Strategy<0> {
    static const int n = 2, q = 2;
    std::function<void(std::string)> query;
    Strategy() {
        query = [this](std::string s) {
            static auto *obj = this;
            int res = ::query(s);
            res += tot;
            res -= std::count(s.begin(), s.end(), 'F');
            res /= 2;
            obj->receive(res);
        };
    }
    void solve() {
        query("TF");
        query("FT");
    }
    std::string ans;
    int last = -1;
    void receive(int res) {
        if (last == -1) {
            last = res;
        } else {
            ans += "FT"[last];
            ans += "FT"[res];
        }
    }
    std::string answer() {
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n;
    
    tot = query(std::string(n, 'T'));
    
    Strategy<7> s;
    s.solve();
    
    std::cout << s.answer().substr(0, n) << "\n";
    
    return 0;
}