#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

const int N = 111111;
int n;
int a[N], b[N];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { 
        scanf("%d", a + i);
        b[i] = a[i]; 
       }

    sort(a, a + n);

    vector<int> c;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) c.push_back(i);

    if (c.size() > 2) {
        puts("NO");
        return 0;
    }

    if (c.size() == 2) {
        int i = c[0];
        int j = c[1];

        if (a[i] == b[j] && a[j] == b[i]) {
            cout << "YES";
            return 0;
        }
    }
    if (c.size() < 2) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;


    
    return 0;
}