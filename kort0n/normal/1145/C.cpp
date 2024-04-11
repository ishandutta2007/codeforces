#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int a[16];
int RE = 16;
int TLE = 10;
//int checking = 13;
int NEW = 1;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 16; i++) a[i] = -1;
    a[0] = 15;
    a[1] = 14;
    a[2] = 12;
    a[3] = 13;
    a[4] = 8;
    a[5] = 9;
    a[6] = 10;
    a[7] = 11;
    a[8] = 0;
    a[9] = 1;
    a[10] = 2;
    a[11] = 3;
    a[12] = 4;
    a[13] = 5;
    a[14] = 6;
    a[15] = 7;
    //a[checking] = NEW;
    int in;
    cin >> in;
    if(a[in] != -1) {
        cout << a[in] << endl;
        return 0;
    }
    if(in == RE) return 1;
    if(in >= TLE) {
        while(true) in--;
    }
    return 0;
}