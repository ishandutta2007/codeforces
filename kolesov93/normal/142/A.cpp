#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    long long n;
    cin >> n;
    
    vector<ll> as;
    for (ll i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            as.push_back(i);
            as.push_back(n/i);
            
        }
    
    long long ans1 = (ll) 1e18, ans2 = 0;
    for (int i = 0; i<as.size(); ++i) {
        ll a = as[i];
        for (ll b = 1; n / a / b >= b; ++b) {
            if ((n % (a * b)) == 0) {
                ll c = n / a / b;
                long long m = (a + 1) * (b + 2) * (c + 2);
                ans1 = min(ans1, m - n);
                ans2 = max(ans2, m - n);
            }
        }
    }
    
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}