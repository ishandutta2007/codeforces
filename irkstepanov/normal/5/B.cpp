#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    vector <string> in;
    in.pb("");

    int lmax = 0;

    string s;
    while (getline(cin, s))
    {
        in.pb(s);
        lmax = max(lmax, (int) s.size());
    }

    in.pb("");

    int st = 0;

    for (int i = 0; i < in.size(); i++)
    {
        if (!i || i == (int) in.size() - 1)
        {
            for (int j = 0; j < lmax + 2; j++)
                cout << '*';
            if (!i) cout << "\n";
        }
        else
        {
            int l = 0, r = 0;
            while (in[i].size() + l + r < lmax)
            {
                if (!st) ++r;
                else ++l;
                st = 1 - st;
                if (in[i].size() + l + r < lmax)
                {
                    if (st) ++l;
                    else ++r;
                    st = 1 - st;
                }
            }
            cout << '*';
            for (int j = 0; j < l; j++)
                cout << ' ';
            cout << in[i];
            for (int j = 0; j < r; j++)
                cout << ' ';
            cout << '*';
            cout << "\n";
        }
    }

}