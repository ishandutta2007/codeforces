#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

int n,c;

int main(){
    IOS;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i+=2) c += a[i+1]-a[i];
    
    cout << c;
    return 0;
}