#include <bits/stdc++.h>

using namespace std;

const int N = 7005;
const int M = 1e5 + 10;

bitset<N> divi[N];

bitset<N> f[N];
void prepare() {
    for(int i = 1; i < N; i++) 
        for(int j = i; j < N; j += i) divi[j][i] = 1;
    for(int i = 1; i < N; i++) f[i][i] = 1;

    //for(int i = 1; i < N; i++) cout << divi[i] << '\n';

    for(int i = N - 1; i >= 1; i--)
        for(int j = i + i; j < N; j += i) f[i] ^= f[j];
    //for(int i = 1; i < N; i++) cout << f[i] << '\n';
}

bitset<N> a[M];
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, test;
    cin >> n >> test;
    while (test--) {
        int type, x, y, z;
        cin >> type >> x >> y;
        if (type == 1) {
            a[x] = divi[y];
            //cout << a[x] << '\n';
        } 
        if (type == 2) {
            cin >> z;
            a[x] = a[y] ^ a[z];
        }
        if (type == 3) {
            cin >> z;
            a[x] = a[y] & a[z];
        }
        if (type == 4) {
            cout << (a[x] & f[y]).count() % 2;
        }

        //for(int i = 1; i <= n; i++) cout << a[i] << '\n';
        //cout << '\n';
    }
}