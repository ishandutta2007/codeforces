#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;

template <typename _Tp>
struct StarrySkyTree
{
    int N, head;
    _Tp defaultMin;
    std::vector<_Tp> range_min, range_add;
    static inline _Tp f(_Tp x, _Tp y) noexcept
    {
        return std::min(x, y);
    }

    inline void _merge(int pos)
    {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<_Tp> &data_init, _Tp default_min)
    {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        defaultMin = default_min;
        range_min.assign(head * 2, defaultMin);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    StarrySkyTree() = default;
    StarrySkyTree(const std::vector<_Tp> &data_init, _Tp default_min)
    {
        initialize(data_init, default_min);
    }
    void _add(int begin, int end, int pos, int l, int r, _Tp vadd) noexcept
    {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end)
        {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    void add(int begin, int end, _Tp vadd) noexcept
    {
        return _add(begin, end, 1, 0, head, vadd);
    }
    _Tp _get(int begin, int end, int pos, int l, int r) const noexcept
    {
        if (r <= begin or end <= l) return defaultMin;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    _Tp get(int begin, int end) const noexcept
    {
        return _get(begin, end, 1, 0, head);
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<pint>> l2r(N + 1);
    vector<int> vinit(N + 2);

    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        vinit[1]++;
        vinit[r + 1]--;
        l2r[l].emplace_back(r, i);
    }
    for (int i = 0; i < vinit.size() - 1; i++) vinit[i + 1] += vinit[i];
    for (int i = 1; i <= N; i++) vinit[i] -= N + 1 - i;

    StarrySkyTree<int> rmq(vinit, 1e7);

    set<pint> s1, s2;
    vector<int> ret1(N), ret2(N);

    bool f = true;
    for (int i = 1; i <= N; i++)
    {
        for (auto r : l2r[i]) s1.emplace(r);
        for (auto r : l2r[i]) s2.emplace(r);

        bool b = false;
        if (f and s2.size() > 1)
        {
            int r2 = next(s2.begin())->first;
            rmq.add(0, r2 + 1, -1);
            int mi = rmq.get(i + 1, N + 1);
            rmq.add(0, r2 + 1, 1);
            if (mi >= 0) b = true;
        }
        if (b)
        {
            int r2 = next(s2.begin())->first;
            rmq.add(1, r2 + 1, -1);
            ret2[next(s2.begin())->second] = i;
            s2.erase(next(s2.begin()));
            f = false;
        }
        else
        {
            int r1 = s2.begin()->first;
            rmq.add(1, r1 + 1, -1);
            ret2[s2.begin()->second] = i;
            s2.erase(s2.begin());
        }

        ret1[s1.begin()->second] = i;
        s1.erase(s1.begin());
    }
    cout << (ret1 != ret2 ? "NO" : "YES") << '\n';
    for (auto x : ret1) cout << x << ' ';
    cout << '\n';
    if (ret1 != ret2)
    {
        for (auto x : ret2) cout << x << ' ';
        cout << '\n';
    }
}