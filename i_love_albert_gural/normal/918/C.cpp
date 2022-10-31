#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node {
    int sum, low;
    node(int _sum = 0, int _low = 0) {
        sum = _sum;
        low = _low;
    }
    node operator+(const node &o) const {
        return node(sum + o.sum, min(low, sum + o.low));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string s;
    cin >> s;

    int ans = 0;
    seg_tree<node> st(s.length());

    for (int i = 0; i < s.length(); i++) {
        fill(all(st.value), node());

        vector<int> q;
        int open = 0;

        int sum = 0;
        for (int j = i; j < s.length(); j++) {
            if (s[j] == '(') {
                st.upd(j, node(1, 0));
                sum++;
            }
            else if (s[j] == ')') {
                st.upd(j, node(-1, -1));
                sum--;
            }
            else {
                q.push_back(j);
                st.upd(j, node(-1, -1));
                sum--;
            }

            if (sum % 2 != 0) {
                // Impossible, don't bother
                continue;
            }

            while (sum > 0 && open > 0) {
                st.upd(q[open - 1], node(-1, -1));
                open--;
                sum -= 2;
            }

            while (sum < 0 && open < q.size()) {
                st.upd(q[open], node(1, 0));
                open++;
                sum += 2;
            }

            if (sum == 0) {
                node tot = st.query(i, j);
                if (tot.low == 0)
                    ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}