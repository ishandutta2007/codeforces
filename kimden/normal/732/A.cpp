#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//const int MAXN = 100002;

//

int main() {
    ios_base::sync_with_stdio(false);
    int k, r;
    cin >> k >> r;
    int i = 1;
    while((k * i) % 10 != r && (k * i) % 10 != 0){
        i++;
    }
    cout << i;
    return 0;
}