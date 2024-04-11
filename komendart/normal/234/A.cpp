#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] == 'R')
        {
            cout << n / 2 + i + 1 << ' ' << i + 1 << endl;
        }
        else
        {
            cout << i + 1 << ' ' << n / 2 + i + 1 << endl;
        }
    }

    return 0;
}