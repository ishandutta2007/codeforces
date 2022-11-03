#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;

int query(int x1, int y1, int x2, int y2){
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    string s;
    cin >> s;
    if(s == "BAD"){
        exit(0);
    }
    if(s == "YES"){
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int x, y;
    string s, t;
    x = y = 0;
    while(x + y < n - 1){
        if(query(x + 1, y, n - 1, n - 1)){
            s += 'D';
            ++x;
        }else{
            s += 'R';
            ++y;
        }
    }
    x = y = n - 1;
    while(x + y > n - 1){
        if(query(0, 0, x, y - 1)){
            t += 'R';
            --y;
        }else{
            t += 'D';
            --x;
        }
    }
    reverse(all(t));
    cout << "! " << s << t << endl;
}