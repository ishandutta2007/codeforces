#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    int a, b;
    cin >> a >> b;

    int t = a * b;
    int win = 0;

    while (t > 0)
    {
        //cout << t << "\n";
        t -= (a + b - 1);
        --a, --b;
        win = 1 - win;
    }

    cout << (win ? "Akshat" : "Malvika");

}