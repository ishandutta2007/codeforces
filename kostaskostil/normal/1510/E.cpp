#include <bits/stdc++.h>
#pragma GCC optimize ("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long double ld;

int n;
double x, y;
string s;

vector<pair<pair<ld, ld>, pair<ld, string> > > centri_mass[100][100];
map<int, set<pair<ld, int> > > st[100];

pair<pair<ld, ld>, ld> areaup(ld x)
{
    ld m1 = x;
    ld m2 = 0.5;

    ld x1 = 0.5;
    ld y1 = x / 2;

    ld x2 = 2.0/3;
    ld y2 = x + 1.0/3;
    return { { (m1 * x1 + m2 * x2) / (m1+m2), (m1 * y1 + m2 * y2) / (m1+m2) }, m1+m2 };
}
pair<pair<ld, ld>, ld> areadown(ld x)
{
    ld m1 = x;
    ld m2 = -0.5;

    ld x1 = 0.5;
    ld y1 = x / 2;

    ld x2 = 2.0/3;
    ld y2 = x - 1.0/3;
    return { { (m1 * x1 + m2 * x2) / (m1+m2), (m1 * y1 + m2 * y2) / (m1+m2) }, m1+m2 };
}

void perebor(int i, int open, int closed, ld xcm, ld ycm, ld m)
{
    centri_mass[i-1][open-closed].pb({{xcm, ycm}, {m, s}});

    if (i==n+1)
    {
//        cout<<s<<" "<<xcm<<" "<<ycm<<" "<<m<<"\n";
//        if ((abs(xcm-x) < 1e-8) and (abs(ycm-y) < 1e-8))
//            cout<<s<<"\n", exit(0);
        return;
    }

    if (open > closed)
    {
        s+=')';

        auto pa = areadown(open - closed);
        perebor(i+1, open, closed+1, (xcm * m + (i-1 + pa.fi.fi) * pa.se) / (m + pa.se),
                                     (ycm * m + pa.fi.se * pa.se) / (m + pa.se), m + pa.se);

        s.pop_back();
    }

    if (open < n)
    {
        s+='(';

        auto pa = areaup(open - closed);
        perebor(i+1, open+1, closed, (xcm * m + (i-1 + pa.fi.fi) * pa.se) / (m + pa.se),
                                     (ycm * m + pa.fi.se * pa.se) / (m + pa.se), m + pa.se);

        s.pop_back();
    }

}

pair<double, string> ans = { 1e9, "" };
void try_(int i, auto pa, int j)
{
    auto pax = centri_mass[n][i][j];

            ld m = pa.se.fi + pax.se.fi;

            ld curx = (pa.fi.fi * pa.se.fi + (2*n - pax.fi.fi) * pax.se.fi ) / m;
            ld cury = (pa.fi.se * pa.se.fi + pax.fi.se * pax.se.fi) / m;
            if (( abs(curx - x) < 1e-3 ) and
                ( abs(cury - y) < 1e-3 ))
                {
                    string s = pa.se.se;
                    string t = pax.se.se;
                    reverse(t.begin(), t.end());
                    string q;
                    for (char c : s)
                        q+=c;
                    for (char c : t)
                        q+=char('(' + ')' - c);
                    ans = min(ans, {abs(curx - x)+abs(cury - y), q});
                }
}

const ld mult = 1e4;
const ld divi = 1e-4;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x>>y;
    n/=2;
    perebor(1, 0, 0, 0, 0, 0);

    for (int i=0; i<100; i++)
        for (size_t j=0; j<centri_mass[n][i].size(); j++)
    {
        auto pa = centri_mass[n][i][j];
        st[i][ ((int) (pa.fi.fi * mult ))- 1].insert({ pa.fi.se, j});
        st[i][ ((int) (pa.fi.fi * mult ))].insert({ pa.fi.se, j});
        st[i][ ((int) (pa.fi.fi * mult ))+ 1].insert({ pa.fi.se, j});
    }

    for (int i=0; i<100; i++)
        for (auto pa : centri_mass[n][i])
            for (double mx = 0.5; mx < 18*18 / 2.0 + 0.1; mx += 0.5)
        {
            ld m = pa.se.fi + mx;

            double xf = 2*n - (x * m - pa.fi.fi * pa.se.fi) / mx;
            double yf = (y * m - pa.fi.se * pa.se.fi) / mx;

            if (!st[i].count((int) (xf * mult)))
                continue;
            auto beg = st[i][((int) (xf * mult ))].lower_bound( { yf - divi, 0} );
            auto en = st[i][((int) (xf * mult ))].lower_bound( { yf + divi, 0} );
            for (auto it = beg; it != en; it++)
                try_(i, pa, it -> se);
        }

    cout<<ans.se<<endl;
}