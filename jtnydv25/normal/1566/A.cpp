#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    while(t--){
        ll n, s; cin >> n >> s;
        ll L = (n + 1) / 2 - 1, R = n - (n + 1) / 2;
        cout << s / (R + 1) << endl;
    }
}