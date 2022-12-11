#include <iostream>
#include <map>

#define mp make_pair

using namespace std;

const int inf = 1000000;
typedef pair <int, int> pii;

int main()
{

    int n;
    cin >> n;
    int ymin = 0, ymax = 0;

    int x = 0, y = 0;
    map <pii, char> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
        {
            while (a--)
            {
                ++x, ++y;
                m[mp(x, y)] = '/';
            }
        }
        else
        {
            while (a--)
            {
                ++x, --y;
                m[mp(x, y + 1)] = '\\';
            }
        }
        ymin = min(ymin, y);
        ymax = max(ymax, y);
    }

    int xmax = x;

    for (y = ymax; y >= ymin; y--)
    {
        for (x = 1; x <= xmax; x++)
            if (m.count(mp(x, y))) cout << m[mp(x, y)];
            else cout << " ";
        if (y != ymin) cout << "\n";
    }

}