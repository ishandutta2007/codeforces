#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    IOS;
    int n;
    cin >> n;
    int ans = n + 1;
	for(int d = 1; 1ll*d*d <= n; d++)
	{
		int o = n / d + (n % d > 0);
		ans = min(ans, d + o);
	}
 
	cout << ans;

    return 0;
}