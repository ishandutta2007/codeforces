#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 300002;
ll t[MAXN], w[MAXN], num[MAXN];
map<ll, ll> st;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    n++;
    int a, b, c, d;
    while(1){
        a = n/1000;
        b = (n/100)%10;
        c = (n/10)%10;
        d = n%10;
        if((a-b)*(b-c)*(c-d)*(d-a)*(a-c)*(b-d) != 0){
            break;
        }
        n++;
    }
    cout << n;
    return 0;
}