#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

struct data
{
    int kol;
    string s;
};

int n;
vector <vector <int> > m;

data f ()
{
    vector <vector <int> > d2 (n, vector <int> (n)), d5 (n, vector <int> (n));
    vector <vector <int> > p2 (n, vector <int> (n)), p5 (n, vector <int> (n));
    while (m[0][0] % 2 == 0 && m[0][0])
    {
        ++d2[0][0];
        m[0][0] /= 2;
    }
    while (m[0][0] % 5 == 0 && m[0][0])
    {
        ++d5[0][0];
        m[0][0] /= 5;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
        if (!i && !j) continue;
        if (!i)
        {
            d2[i][j] = d2[i][j - 1];
            p2[i][j] = 0;
            d5[i][j] = d5[i][j - 1];
            p5[i][j] = 0;
        }
        else if (!j)
        {
            d2[i][j] = d2[i - 1][j];
            p2[i][j] = 1;
            d5[i][j] = d5[i - 1][j];
            p5[i][j] = 1;
        }
        else
        {
            if (d2[i - 1][j] < d2[i][j - 1])
            {
                d2[i][j] = d2[i - 1][j];
                p2[i][j] = 1;
            }
            else
            {
                d2[i][j] = d2[i][j - 1];
                p2[i][j] = 0;
            }
            if (d5[i - 1][j] < d5[i][j - 1])
            {
                d5[i][j] = d5[i - 1][j];
                p5[i][j] = 1;
            }
            else
            {
                d5[i][j] = d5[i][j - 1];
                p5[i][j] = 0;
            }
        }
        while (m[i][j] % 2 == 0 && m[i][j])
        {
            ++d2[i][j];
            m[i][j] /= 2;
        }
        //cout << i << " " << j << "\n";
        while (m[i][j] % 5 == 0 && m[i][j])
        {
            ++d5[i][j];
            m[i][j] /= 5;
        }
    }
    data ans;
    if (d2[n - 1][n - 1] < d5[n - 1][n - 1])
    {
        ans.kol = d2[n - 1][n - 1];
        ans.s = "";
        int i = n - 1, j = n - 1;
        while (i || j)
        {
            if (p2[i][j]) {ans.s += "D"; --i;}
            else {ans.s += "R"; --j;}
        }
        i = 0, j = (int) ans.s.size() - 1;
        while (i < j)
        {
            swap (ans.s[i], ans.s[j]);
            ++i, --j;
        }
    }
    else
    {
        ans.kol = d5[n - 1][n - 1];
        ans.s = "";
        int i = n - 1, j = n - 1;
        while (i || j)
        {
            if (p5[i][j]) {ans.s += "D"; --i;}
            else {ans.s += "R"; --j;}
        }
        i = 0, j = (int) ans.s.size() - 1;
        while (i < j)
        {
            swap (ans.s[i], ans.s[j]);
            ++i, --j;
        }
    }
    return ans;
}

int main()
{

    cin >> n;
    m.resize(n);

    bool is_zero = false;

    for (int i = 0; i < n; i++)
    {
        m[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if (!m[i][j]) is_zero = true;
        }
    }

    if (!is_zero)
    {
        data d = f();
        cout << d.kol << "\n" << d.s;
        return 0;
    }

    int posi, posj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (!m[i][j])
    {
        posi = i;
        posj = j;
    }

    data ans1;
    ans1.kol = 1;
    ans1.s = "";
    for (int i = 0; i < posi; i++)
        ans1.s += "D";
    for (int j = 0; j < posj; j++)
        ans1.s += "R";
    for (int i = posi; i < n - 1; i++)
        ans1.s += "D";
    for (int j = posj; j < n - 1; j++)
        ans1.s += "R";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (!m[i][j]) m[i][j] = 10;

    data ans2 = f();
    if (ans2.kol < ans1.kol)
    cout << ans2.kol << "\n" << ans2.s;
    else cout << ans1.kol << "\n" << ans1.s;

}