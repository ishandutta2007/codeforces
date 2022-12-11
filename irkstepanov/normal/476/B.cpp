#include <iostream>
#include <string>
#include <set>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

const ld eps = 0.000000000000001;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string a, b;
    cin >> a >> b;

    set <string> s;
    s.insert("");

    for (int i = 0; i < (int) b.size(); i++)
    {
        set <string> next;
        if (b[i] == '-' || b[i] == '+')
        {
            for (set <string> :: iterator it = s.begin(); it != s.end(); it++)
                next.insert(*it + b[i]);
        }
        else
        {
            for (set <string> :: iterator it = s.begin(); it != s.end(); it++)
            {
                next.insert(*it + "+");
                next.insert(*it + "-");
            }
        }
        s = next;
    }

    int x = 0;
    for (int i = 0; i < (int) a.size(); i++)
        if (a[i] == '+') ++x;
        else --x;

    int ans = 0;
    for (set <string> :: iterator it = s.begin(); it != s.end(); it++)
    {
        int y = 0;
        string str = *it;
        for (int i = 0; i < (int) str.size(); i++)
            if (str[i] == '+') ++y;
            else --y;
        if (y == x) ++ans;
    }

    cout.precision(10);
    cout << fixed << ans * 1.0 / (int) s.size();

}