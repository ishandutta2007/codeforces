#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int h, m, s, t1, t2;
    while (cin >> h >> m >> s >> t1 >> t2) {
        h = h * 5 % 60;
        t1 = t1 * 5 % 60;
        t2 = t2 * 5 % 60;

        h *= 100;
        m *= 100;
        s *= 100;
        t1 *= 100;
        t2 *= 100;

        if (s != 0) m++;
        if (m != 0) h++;

        vector<int> a;
        a.push_back(h);
        a.push_back(m);
        a.push_back(s);
        a.push_back(t1);
        a.push_back(t2);

        sort(a.begin(), a.end());

        bool f = 0;
        for (int i = 0; i < 5; i++) {
            if (a[i] == t1 && a[(i + 1) % 5] == t2) f = 1;
            if (a[i] == t2 && a[(i + 1) % 5] == t1) f = 1;
            //cout << a[i] << " \n"[i + 1 == 5];
        }
        string s = f ? "YES" : "NO";
        cout << s << endl;
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}