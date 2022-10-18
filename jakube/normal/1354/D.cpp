#include <bits/stdc++.h>
using namespace std;


// Implementation of a Binary Indexed Tree (Fennwick Tree)
class BIT
{
public:
    BIT(int n)
    {
        // Initialize BIT with list in O(n)
        m_array = std::vector<int>(n + 1, 0);
    }

    int prefix_query(int idx)
    {
        // Computes prefix sum of up to including the idx-th element
        int result = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            result += m_array[idx];
        }
        return result;
    }

    void update(int idx, int add)
    {
        // Add a value to the idx-th element
        for (++idx; idx < (int)m_array.size(); idx += idx & -idx) {
            m_array[idx] += add;
        }
    }

private:
    std::vector<int> m_array;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    BIT bit(1'000'002);;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bit.update(x, 1);
    }
    
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x > 0)
            bit.update(x, 1);
        else {
            int L = 0; // <
            int R = 1'000'000;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                if (bit.prefix_query(M) >= -x)
                    R = M;
                else
                    L = M;
            }
            bit.update(R, -1);
        }
    }

    if (bit.prefix_query(1'000'000)) {
        int L = 0;
        int R = 1'000'000;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            if (bit.prefix_query(M))
                R = M;
            else
                L = M;
        }
        cout << R << '\n';
    } else {
        cout << 0 << '\n';
    }
}