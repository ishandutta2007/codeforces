#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

string sv, ev;

int main()
{
    cin >> sv >> ev;
    int l = abs(sv[0] - ev[0]);
    int r = abs(sv[1] - ev[1]);

    char dir[3];
    dir[0] = sv[0] < ev[0] ? 'R' : 'L';
    dir[1] = sv[1] < ev[1] ? 'U' : 'D';
    dir[2] = '\0';

    char dir_l;
    if (l >= r)
        dir_l = sv[0] < ev[0] ? 'R' : 'L';
    else
        dir_l = sv[1] < ev[1] ? 'U' : 'D';

    cout << max(l, r) << endl;
    for (int i = 0; i < min(l, r); ++i)
        cout << dir << endl;
    for (int i = min(l, r); i < max(l, r); ++i)
        cout << dir_l << endl;

    return 0;
}