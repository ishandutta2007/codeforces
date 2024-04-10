// M
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 9, Mod = 1e9 + 7;
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        ll n, d, m;
        cin >> n >> d >> m;
        ll tot = 0;
        vector < ll > A , B;
        for (int i = 1; i <= n; i ++)
        {
                ll a;
                cin >> a;
                if (a <= m)
                        A.push_back(a);
                else
                        B.push_back(a);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int ptr = (int)A.size() - 1;
        while (ptr >= 0)
                tot += A[ptr], ptr --;
        ll Mx = tot;
        for (int i = (int)B.size() - 1; i >= 0; i --)
        {
                ll nd = min(((int)B.size() - i - 1) * (ll)d, (ll)(1e9));
                nd -= i;
                nd -= ptr + 1;
                nd = max(nd, 0LL);
                tot += B[i];
                while (nd > 0 && ptr + 1 < (int)A.size())
                        ptr ++, nd --, tot -= A[ptr];
                if (nd > 0)
                        continue;
                Mx = max(Mx, tot);
        }
        cout << Mx << endl;
        return 0;
}