#include <algorithm>
#include <array>
#include <string>
#include <vector>

struct Suffix {
    using Ranks = std::array<int, 2>;
    // rank and next rank

    int idx;
    Ranks ranks;

    bool operator<(Suffix const& b) { return ranks < b.ranks; }
};

class SuffixArray
{
public:
    SuffixArray(std::string const& s)
    {
        buildSuffixArray(s);
        kasai(s);
    }

    std::vector<int> suffixArray;
    std::vector<int> lcp;

private:
    void buildSuffixArray(std::string const& s)
    {
        // O(n logn logn)
        int n = s.size();
        std::vector<Suffix> suffixes(n);
        for (int i = 0; i < n; i++) {
            suffixes[i] = {i, {{s[i] - '0', i == n - 1 ? -1 : s[i + 1] - '0'}}};
        }
        sort(suffixes.begin(), suffixes.end());

        std::vector<int> indices(n);
        for (int k = 2; k <= n; k *= 2) {
            int rank = 0;
            Suffix::Ranks prev_ranks = {{-1, -1}};
            for (int i = 0; i < n; i++) {
                if (i && prev_ranks < suffixes[i].ranks) {
                    rank++;
                }
                prev_ranks = suffixes[i].ranks;
                suffixes[i].ranks[0] = rank;
                indices[suffixes[i].idx] = i;
            }

            for (int i = 0; i < n; i++) {
                int next_idx = suffixes[i].idx + k;
                suffixes[i].ranks[1] =
                    next_idx < n ? suffixes[indices[next_idx]].ranks[0] : -1;
            }

            sort(suffixes.begin(), suffixes.end());
        }

        suffixArray.resize(n);
        for (int i = 0; i < n; i++) {
            suffixArray[i] = suffixes[i].idx;
        }
    }

    void kasai(std::string const& s)
    {
        int n = s.size();
        lcp.resize(n);

        std::vector<int> inverse(n);
        for (int i = 0; i < n; i++) {
            inverse[suffixArray[i]] = i;
        }

        int k = 0;
        for (int i = 0; i < n; i++) {
            if (inverse[i] == n - 1) {
                k = 0;
            } else {
                int j = suffixArray[inverse[i] + 1];
                while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                    k++;
                }
            }
            lcp[inverse[i]] = k;
            if (k > 0) {
                k--;
            }
        }
    }
};

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    long long result = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '0') {
            result = i + 1;
        }
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    SuffixArray sa(s);

    vector<int> suffixArray;
    vector<int> lcp;
    int mm = 1e9;
    for (int i = 0; i < n; i++) {
        if (t[sa.suffixArray[i]] == '0') {
            lcp.push_back(mm);
            suffixArray.push_back(sa.suffixArray[i]);
            mm = sa.lcp[i];
        }
        mm = min(mm, sa.lcp[i]);
    }

    if (lcp.empty()) {
        cout << result << endl;
        return 0;
    }

    lcp.erase(lcp.begin());
    lcp.push_back(0);

    n = lcp.size();
    vector<int> min_left(n), min_right(n);

    stack<pair<int, int>> st;
    st.push({-1, -1});
    for (int i = 0; i < n; i++) {
        while (st.top().first >= lcp[i]) {
            st.pop();
        }
        min_left[i] = st.top().second + 1;
        st.push({lcp[i], i});
    }
    stack<pair<int, int>> st2;
    st2.push({-1, n});
    for (int i = n-1; i >= 0; i--) {
        while (st2.top().first >= lcp[i]) {
            st2.pop();
        }
        min_right[i] = st2.top().second + 1;
        st2.push({lcp[i], i});
    }

    for (int i = 0; i < n; i++) {
        long long length = min_right[i] - min_left[i];
        result = max(result, length * lcp[i]);
    }
    cout << result << endl;
}