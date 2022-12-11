#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

vector <vector <int> > t;
int n;

int get(int j, int l, int r)
{
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
    {
        if (l & 1) ans = max(ans, t[j][l]);
        if (!(r & 1)) ans = max(ans, t[j][r]);
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int m, k;

    cin >> n >> m >> k;

    t.assign(m, vector <int> (2 * n));
    vector <vector <int> > a(m, vector <int> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        cin >> a[j][i];

    for (int j = 0; j < m; j++)
    {
        for (int i = n; i < 2 * n; i++)
            t[j][i] = a[j][i - n];
        for (int i = n - 1; i; i--)
            t[j][i] = max(t[j][i * 2], t[j][i * 2 + 1]);
    }

    int ans = 0;
    vector <int> v(m, 0);

    for (int l = 0; l < n; l++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += a[j][l];
        if (sum > k) continue;
        int L = l, R = n - 1;
        while (R - L > 1)
        {
            int M = (L + R) / 2;
            sum = 0;
            for (int j = 0; j < m; j++)
                sum += get(j, l, M);
            if (sum > k) R = M;
            else L = M;
        }
        int r;
        sum = 0;
        for (int j = 0; j < m; j++)
            sum += get(j, l, R);
        if (sum <= k) r = R;
        else r = L;
        if (r - l + 1 > ans)
        {
            ans = r - l + 1;
            for (int j = 0; j < m; j++)
                v[j] = get(j, l, r);
        }
    }

    for (int j = 0; j < m; j++)
        cout << v[j] << " ";

}