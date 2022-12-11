#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pii;

int main()
{

    int n, m;
    cin >> n >> m;

    for (int k = n / 2; k >= 0; k--)
        if ((n - k) % m == 0) {cout << n - k << "\n"; return 0;}

    cout << "-1\n";
    return 0;

}