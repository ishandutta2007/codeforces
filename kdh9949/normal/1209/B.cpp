#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 105;

int n, a[N], b[N], c[N], r;
char s[N];

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        c[i] = b[i];
    }
    for(int i = 1; i <= 100000; i++){
        int t = 0;
        for(int j = 0; j < n; j++) t += (s[j] == '1');
        r = max(r, t);
        for(int j = 0; j < n; j++){
            c[j]--;
            if(!c[j]){
                s[j] ^= 1;
                c[j] = a[j];
            }
        }
    }
    cout << r << '\n';
}