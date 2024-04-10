#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> data;
    vector<int> cnt;
    vector<bool> todo;
    int N;

    SegmentTree(int N) : N(N) {
        data.assign(2*N, 0);
        cnt.assign(N, 0);
        for (int i = N-1; i > 0; i--) {
            if (i*2 >= N) cnt[i] = 2;
            else cnt[i] = cnt[i<<1] + cnt[i<<1|1];
        }
        todo.assign(N, false);
    }

    void build(int index) {
        while (index > 1) {
            index >>= 1;
            if (todo[index]) {
                data[index] = cnt[index] - data[index<<1] - data[index<<1|1];
            }
            else {
                data[index] = data[index<<1] + data[index<<1|1];
            }
        }
    }

    void push(int index) {
        for (int s = 20; s > 0; s--) {
            int i = index >> s;
            if (i > 0 && todo[i]) {
                todo[i] = false;
                change(i<<1);
                change(i<<1|1);
            }
        }
    }

    void change(int index) {
        if (index >= N) {
            data[index] = 1 - data[index];
        } else {
            data[index] = cnt[index] - data[index];
            todo[index] = !todo[index];
        }
    }

    void update(int left, int right) {
        left += N;
        right += N;
        int l0 = left, r0 = right;
        
        while (left < right) {
            if (left & 1) {
                change(left);
                left++;
            }
            if (right & 1) {
                right--;
                change(right);
            }
            left >>= 1;
            right >>= 1;
        }

        build(l0);
        build(r0-1);
    }

    void update(int index) {
        index += N;
        data[index] = 1 - data[index];

        while (index > 1) {
            index >>= 1;
            data[index] = data[index<<1] + data[index<<1|1];
        }
    }

    int sum(int left, int right) {
        left += N;
        right += N;

        push(left);
        push(right-1);

        int result = 0;
        while (left < right) {
            if (left&1) {
                result += data[left];
                left++;
            }
            if (right&1) {
                right--;
                result += data[right];
            }

            left>>=1; right>>=1;
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    int m;
    cin >> m;

    vector<SegmentTree> trees(22, {n});
    for (int i = 0; i < n; i++) {
        int num = v[i];
        for (int j = 0; j < 22; j++) {
            if (num & 1)
                trees[j].update(i);
            num >>= 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            long long result = 0;
            for (int b = 0; b < 22; b++) {
                result += (long long)(trees[b].sum(l-1, r)) << b;
            }
            cout << result << '\n';
        }
        if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            // for (int index = l-1; index < r; index++) {
            //     int num = x;
            //     for (int b = 0; b < 22; b++) {
            //         if (num & 1)
            //             trees[b].update(index);
            //         num >>= 1;
            //     }
            // }

            int num = x;
            for (int b = 0; b < 22; b++) {
                if (num & 1) {
                    trees[b].update(l-1, r);
                }
                num >>= 1;
            }
        }
    }
    
    return 0;
}