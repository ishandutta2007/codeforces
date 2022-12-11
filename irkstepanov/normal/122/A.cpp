#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int m[] = {4, 7, 44, 47, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int n;
    cin >> n;
    for (int i = 0; i < 13; i++)
    if (n % m[i] == 0) {cout << "YES"; return 0;}

    cout << "NO";

}