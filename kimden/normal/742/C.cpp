#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[102];
map<int, int> mp;
vector<char> used;
int beg;

ll gcd(ll a, ll b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    used.resize(n, 0);
    int v;
    ll cnt;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(!used[i]){
            beg = i;
            v = i;
            cnt = 0;
            while(!used[v]){
                used[v] = 1;
                v = a[v];
                cnt++;
            }
            if(v != beg){
                cout << -1 << endl;
                return 0;
            }
            if(cnt % 2 == 0){
                cnt /= 2;
            }
            ans = lcm(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}