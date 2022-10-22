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

const int mod = 998244353, mod2 = 1e+7;

int main(){
    IOS;
	int t;
	string s;
	cin >> t;
	while(t--){
	    cin >> s;
	    int n = s.length();
	    int a[n];
	    for (int i = 0; i < n; i++) a[i] = s[i]-'a';
	    sort(a,a+n);
	    if (a[0] == a[n-1]) {cout << "-1\n"; continue;}
	    for (int i = 0; i < n; i++) cout << (char)(a[i]+'a');
	    cout << endl;
	}
    return 0;
}