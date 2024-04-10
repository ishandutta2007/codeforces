#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

#define ll long long

template <typename T>
T next_int() {  
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if (ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * p;
}

const int max_n = (int)1e5 + 227 + 1;
const int max_int = (int)1e9 + 227 + 1;

vector<int> a;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }

    sort(a.rbegin(), a.rend());

    int cnt = k;
    int cur = a[k - 1];
    
    if (cur == 0){
       for (int i = k - 1; i >= 0; i--)
         if (a[i] == 0)
            cnt--;
         return cout << cnt, 0;
    }
    for (int i = k; i < n; i++)
        if (a[i] == cur)
            cnt++;
    
    cout << cnt;
    return 0;
}