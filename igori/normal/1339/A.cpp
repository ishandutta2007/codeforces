#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        cout << a << "\n";
    }
}