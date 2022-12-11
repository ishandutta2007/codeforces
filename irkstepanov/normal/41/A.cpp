#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {cout << "NO"; return 0;}

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[(int) b.size() - 1 - i]) {cout << "NO"; return 0;}

    cout << "YES";

}