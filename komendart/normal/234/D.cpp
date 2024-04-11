#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int m, k;
    cin >> m >> k;

    vector<bool> favourite(m + 1, false);
    for (int i = 0; i < k; ++i)
    {
        int a; cin >> a;
        favourite[a] = true;
    }

    int n;
    cin >> n;

    vector< pair<int, int> > films(n, make_pair(0, 0));

    for (int i = 0; i < n; i += 1)
    {
        string name; cin >> name;
        int d; cin >> d;

        int a = 0, b = 0, c = 0;
        for (int j = 0; j < d; ++j)
        {
            int id; cin >> id;
            if (id == 0)
            {
                c += 1;
            }
            else if (favourite[id])
            {
                a += 1;
            }
            else
            {
                b += 1;
            }
        }

        int minimal = a + max(0, c - (m - k - b));
        int maximal = a + min(c, k - a);
        films[i] = make_pair(minimal, maximal);
    }

    for (int i = 0; i < n; i += 1)
    {
        bool is_good = true, is_bad = false;
        for (int j = 0; j < n; j += 1)
        {
            if (i == j)
            {
                continue;
            }
            if (films[i].second < films[j].first)
            {
                is_good = false;
            }
            if (films[i].first < films[j].second)
            {
                is_bad = true;
            }
        }

        if (!is_bad)
        {
            cout << 0 << endl;
        }
        else if (!is_good)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }

    return 0;
}