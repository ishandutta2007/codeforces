#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

template <typename T>
class Matrix : public std::vector<std::vector<T>> {
public:
    Matrix(int n, int m, T init=0) 
        : std::vector<std::vector<T>>(n, std::vector<T>(m, init)) {}
};

template <typename T>
std::vector<T> operator*(std::vector<T> const& v, Matrix<T> const& M) {
    std::vector<T> res(v.size(), 0);
    for (int i = 0; i < (int)res.size(); i++) {
        for (int j = 0; j < (int)res.size(); j++)
            res[i] += v[j] * M[j][i];
        res[i] %= MOD;
    }
    return res;
}

template <typename T>
Matrix<T> operator*(Matrix<T> const& A, Matrix<T> const& B) {
    auto res = A;
    for (int i = 0; i < (int)res.size(); i++)
        res[i] = A[i] * B;
    return res;
}

struct Event
{
    long long time;
    int a;
    bool start;
    bool operator<(Event const& other) const {
        return time < other.time;
    }
};

using DP = vector<long long>;

DP apply(DP cur, Matrix<long long> M, long long l, long long r) {
    long long duration = r - l;
    while (duration) {
        if (duration & 1)
            cur = cur * M;
        M = M * M;
        duration >>= 1;
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long m;
    cin >> m;

    vector<Event> events(2*n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        long long l, r;
        cin >> l >> r;
        events[2*i] = {l, a, true};
        events[2*i+1] = {r+1, a, false};
    }
    events.back() = {m + 1, 1, false};
    sort(events.begin(), events.end());
    
    auto createTransition = [](auto obst) {
        Matrix transition(3, 3, 0LL);
        transition[0] = {1, 1, 0};
        transition[1] = {1, 1, 1};
        transition[2] = {0, 1, 1};
        for (int i = 0; i < 3; i++) {
            if (obst[i]) {
                for (int j = 0; j < 3; j++) {
                    transition[j][i] = 0;
                }
            }
        }
        return transition;
    };

    long long pos = 1;
    array<int, 3> obst = {0, 0, 0};
    DP cur = {0, 1, 0};

    for (auto e : events) {
        if (e.time - 1 > pos) {
            cur = apply(cur, createTransition(obst), pos, e.time - 1);
            pos = e.time - 1;
        }
        if (e.start)
            obst[e.a-1]++;
        else
            obst[e.a-1]--;
    }
    cout << cur[1];
}