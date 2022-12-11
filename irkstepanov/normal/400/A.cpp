#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;

int main()
{

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        vector <pair <int, int> > v;
        for (int a = 1; a <= 12; a++)
            if (12 % a == 0)
        {
            int b = 12 / a;
            int ok = 0;
            for (int i = 0; i < b; i++)
            {
                int flag = 1;
                for (int j = 0; j < 12; j++)
                    if (j % b == i && s[j] != 'X') flag = 0;
                if (flag) ok = 1;
            }
            if (ok) v.pb(mp(a, b));
        }
        cout << v.size() << " ";
        for (int i = 0; i < v.size(); i++)
            cout << v[i].first << "x" << v[i].second << " ";
        cout << "\n";
    }

}