#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> deltas(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size());
    for (int i = 1; i < a.size(); i++)
    {
        long long d = b[i] - a[i];
        res[i] = d;
        for (int j = i; j < a.size(); j += i)
            a[j] += d;
    }
    return res;
}

int main()
{
    const int N = 1e6;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    b[1] = 0;
    vector<long long> res1 = deltas(a, b);
    b[1] = 1;
    vector<long long> res2 = deltas(a, b);
    b[1] = N;
    vector<long long> res3 = deltas(a, b);

    //for (auto e : res1) cout << e << " "; cout << "\n";
    //for (auto e : res2) cout << e << " "; cout << "\n";
    //for (auto e : res3) cout << e << " "; cout << "\n";

    for (int i = 1; i <= n; i++)
        assert(res1[i] >= res2[i] || res1[i] + N == res3[i]);

    long long C = 0;
    for (int i = 1; i <= n; i++)
        if (res1[i] == res2[i]) C += abs(res1[i]);

    vector<long long> ans(N + 1);
    vector<long long> d_counter(N + 1);
    long long counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res1[i] == res2[i]) continue;
        ans[0] += abs(res1[i]);
        if (res1[i] + N == res3[i])
        {
            if (res1[i] >= 0) counter++;
            else
            {
                counter--;
                long long zero = -res1[i];
                if (zero <= N)
                    d_counter[zero] += 2;
            }
        }
        else if (res1[i] - N == res3[i])
        {
            if (res1[i] <= 0) counter++;
            else
            {
                counter--;
                long long zero = res1[i];
                if (zero <= N)
                    d_counter[zero] += 2;
            }
        }
        else if (res1[i] != res2[i])
        {
            long long d = res3[i] - res1[i];
            long long ext = N / 2 - d / 2;
            //cout << "! " << i << " " << d << " " << ext << "\n";
            assert(0 <= ext && ext <= N);
            if (res1[i] - ext >= 0)
            {
                counter--;
                d_counter[ext] += 2;
            }
            else
            {
                long long first_zero = res1[i];
                long long second_zero = N - res3[i];
                if (0 < first_zero)
                {
                    counter--;
                    if (first_zero <= N)
                        d_counter[first_zero] += 2;
                }
                else
                    counter++;
                d_counter[ext] -= 2;
                if (second_zero <= N)
                {
                    d_counter[second_zero] += 2;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        ans[i] = ans[i - 1] + counter;
        counter += d_counter[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
//        ll ans = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            if (res1[i] + N == res3[i])
//            {
//                ans += abs(res1[i] + x);
//            }
//            else if (res1[i] != res2[i])
//            {
//                long long d = res3[i] - res1[i];
//                long long ext = N / 2 - d / 2;
//                //cout << res1[i] << " " << res2[i] << " " << res3[i] << " " << ext << "\n";
//                if (x <= ext)
//                    ans += abs(res1[i] - x);
//                else
//                    ans += abs(res1[i] - ext + (x - ext));
//            }
//        }
//        cout << ans + C << "\n";
        cout << ans[x] + C << "\n";
    }
}