#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 5e5 + 9, Mod = 1e9 + 9;
int n, __cnta, __cntb;
pair < int , int > A[N];
inline bool Solve(int md)
{
        vector < int > v1, v2, v3, V;
        for (int i = 1; i <= n; i ++)
                v2.push_back(A[i].x),
                v1.push_back(A[i].x - md),
                v3.push_back(A[i].x + md);
        merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(V));
        V.swap(v2); V.clear();
        merge(v2.begin(), v2.end(), v3.begin(), v3.end(), back_inserter(V));

        int leb = -Mod, rib = Mod;

        int le = 0;
        int Mnr = Mod;
        int Mxl = -Mod;
        int id = 1;
        for (le = 0; le < (int)V.size(); le ++)
        {
                if (V[le] < A[1].x)
                        continue;
                // If c == A[i].x
                if (V[le] - A[1].x > md)
                        break;
                int c = V[le];
                while (id < n && V[le] >= A[id + 1].x)
                {
                        Mxl = max(Mxl, - A[id].x + A[id].y - md);
                        Mnr = min(Mnr, A[id].y + md);
                        id ++;
                }
                Mxl = max(Mxl, - A[id].x + A[id].y - md);
                Mnr = min(Mnr, A[id].y + md);
                //cout << c << " :: " << Mxl << " , " << Mnr << endl;
                if (c + Mxl > Mnr)
                        break;
                __cnta = c;
                //__cntb = Mnr;
                leb = max(leb, Mxl + c);
                rib = min(rib, Mnr);
        }
        le --;

//      cout << V[le] << " = " << id << " :: " << leb << " , " << rib << endl;

        int ri = (int)V.size() - 1;
        Mnr = Mod;
        Mxl = -Mod;
        id = n;
        for (; ri >= 0; ri --)
        {
                if (ri < le)
                        break;
                if (V[ri] > A[n].x)
                        continue;
                if (A[n].x - V[ri] > md)
                        break;
                int c = -V[ri];
                while (id > 1 && V[ri] <= A[id - 1].x)
                {
                        Mxl = max(Mxl, - (-A[id].x) + (-A[id].y) - md);
                        Mnr = min(Mnr, (-A[id].y) + md);
                        id --;
                }
                Mxl = max(Mxl, - (-A[id].x) + (-A[id].y) - md);
                Mnr = min(Mnr, (-A[id].y) + md);
                if (c + Mxl > Mnr)
                        break;

                //cout << "::: " << Mxl + c << " ::::: " << Mnr << endl;
                //leb = max(leb, Mxl + c);
                //rib = min(rib, Mnr);
                leb = max(leb, -Mnr);
                rib = min(rib, -Mxl-c);
        }
        ri ++;
        if (le < ri)
                return 0;
        if (leb > rib)
                return 0;
        __cntb = leb;

        return 1;
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
                string ss;
                cin >> ss;
                int a = 0, b = 0;
                for (char ch : ss)
                        if (ch == 'B') a ++;
                        else b ++;
                assert((int)ss.size() == a + b);
                A[i] = make_pair(a, b);
        }
        sort(A + 1, A + n + 1);
        n = unique(A + 1, A + n + 1) - A - 1;
/*      for (int i = 1; i <= n; i ++)
                cout << A[i].x << " " << A[i].y << endl;

        cout << "Solve : " << Solve(12) << endl;
        cout << "=== " << __cnta << " : " << __cntb << endl;
        return 0;
*/

        int le = -1, ri = N, md;
        while (ri - le > 1)
        {
                md = (le + ri) >> 1;
                if (Solve(md))
                        ri = md;
                else
                        le = md;
        }
        Solve(ri);
//      cout << "=== " << __cnta << " : " << __cntb << endl;

        int Mx = 0;
        for (int i = 1; i <= n; i ++)
        {
                if (A[i].x <= __cnta && A[i].y <= __cntb)
                        Mx = max({Mx, __cnta - A[i].x, __cntb - A[i].y});
                else if (A[i].x >= __cnta && A[i].y >= __cntb)
                        Mx = max({Mx, A[i].x - __cnta, A[i].y - __cntb});
                else
                        Mx = max(Mx, abs(A[i].x - __cnta) + abs(A[i].y - __cntb));
        }
        if (Mx != ri)
                assert(0);
        //cerr << "==== " << Mx << endl;


        cout << ri << endl;
        for (int i = 0; i < __cnta; i ++)
                cout << "B";
        for (int i = 0; i < __cntb; i ++)
                cout << "N";
        cout << endl;
        return 0;
}