#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

bool inside(lol l, lol r, lol n){
    return (l < n && n <= r);
}

bool test(lol a, lol b, lol lx, lol rx, lol ly, lol ry){
    lol prod = a * b;
    lol num = (rx / prod) * prod;

    if(inside(lx, rx, num)){
        cout << num << ' ' << ry << '\n';
        return true;
    }

    num = (ry / prod) * prod;

    if(inside(ly, ry, num)){
        cout << rx << ' ' << num << '\n';
        return true;
    }

    lol ans_x = (rx / a) * a;

    if(inside(lx, rx, ans_x)){
        lol ans_y = (ry / b) * b;

        if(inside(ly, ry, ans_y)){
            cout << ans_x << ' ' << ans_y << '\n';
            return true;
        }
    }

    ans_x = (rx / b) * b;

    if(inside(lx, rx, ans_x)){
        lol ans_y = (ry / a) * a;

        if(inside(ly, ry, ans_y)){
            cout << ans_x << ' ' << ans_y << '\n';
            return true;
        }
    }

    return false;
}

void solve(lol a, lol b, lol c, lol d){
    lol prod = a * b;

    for(lol i = 1; i * i <= prod; ++i) if(prod % i == 0){
        lol j = prod / i;
        if(test(i, j, a, c, b, d)) return;
    }

    cout << "-1 -1\n";
}

void brute(){
    lol c = rand() % 100 + 1, d = rand() % 100 + 1;
    lol a = rand() % c + 1, b = rand() % d + 1;

    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

    lol p = a * b;
    bool ans = 0;

    for(lol i = a + 1; i <= c; ++i){
        bool ok = 0;

        for(lol j = b + 1; j <= d; ++j)
            if(i * j % p == 0){
                cout << i << ' ' << j << ' ';
                ok = 1;
                break;
            }

        if(ok){
            ans = 1;
            break;
        }
    }

    if(!ans) cout << "-1 -1 ";

    solve(a, b, c, d);
    cout << flush;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //for(int i = 0; i < 10; ++i) brute();

    int t;
    cin >> t;

    while(t--){
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
}