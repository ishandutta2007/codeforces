#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 2;

ll n, m;
string names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 12; i++)
    {
        if (names[i] == s)
            n = i;
    }
    cin >> m;
    n = (n + m) % 12;
    cout << names[n] << endl;
}