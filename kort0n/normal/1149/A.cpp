#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int num[3];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        num[a]++;
    }
    if(num[1] >= 1 && num[2] >= 1) {
        cout << "2 1 ";
        num[2]--;
        num[1]--;
        for(int i = 1; i <= num[2]; i++) {
            cout << "2 ";
        }
        for(int i = 1; i <= num[1]; i++) {
            cout << "1 ";
        }
        cout << endl;
        return 0;
    }
    for(int i = 1; i <= num[2]; i++) {
        cout << "2 ";
    }
    for(int i = 1; i <= num[1]; i++) {
        cout << "1 ";
    }
    cout << endl;
    return 0;
}