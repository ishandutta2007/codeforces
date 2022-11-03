#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;

vector<int> v;
int n;

int query(int i){
    int a, b;
    cout << "? " << (i % n) + 1 << endl;
    cin >> a;
    cout << "? " << (i + n / 2) % n + 1 << endl;
    cin >> b;
    v[(i % n)] = a;
    v[(i + n / 2) % n] = b;
    if(a == b){
        cout << "! " << (i % n) + 1 << endl;
        exit(0);
    }
    return b - a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    v.resize(n, -1);
    int x = query(0);
    int L, R, mid;
    if(x < 0){
        L = n / 2;
        R = n;
    }else{
        L = 0;
        R = n / 2;
    }
    while(R - L > 1){
        mid = (R + L) / 2;
        int x = query(mid);
        if(x > 0){
            L = mid;
        }else{
            R = mid;
        }
    }
    cout << "! -1" << endl;



    return 0;
}