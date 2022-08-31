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
#endif

void solve(int testcase){
    int a = 0, b = 0, c, d; cin >>c>>d;
    c-=a; d-=b;
    if(abs(c) % 2 != abs(d) % 2){
        cout << -1 << endl;
        return;
    }
    if(c==0&&d==0){
        cout << 0 << endl;
        return;
    }
    cout << (abs(c) == abs(d) ? 1 : 2) << endl;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        // cout << "Case #"<<i<<": ";
        solve(i);
    }
}