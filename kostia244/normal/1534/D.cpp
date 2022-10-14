#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
	int n;
    map<int, vector<int>> ans;
vector<int> ask(int a) {
    if(ans.count(a)) return ans[a];
    cout << "? " << a+1 << endl;
    vector<int> b(n);
    for(auto &i : b) cin >> i;
    return ans[a] = b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
    cin >> n;
    auto x = ask(0);
    int o = 0;
    for(int i = 0; i < n; i++) o += x[i]&1;
    vector<int> list;
    int bound = (n+1)/2;
    for(int i = 0; i < n; i++) if((x[i]&1)^!((n-o) > bound)) list.push_back(i);
    for(auto i : list) ask(i);
    cout << "!\n";
    for(auto i : list) {
        for(int j = 0; j < n; j++) {
            if(ans[i][j] == 1)
                cout << i+1 << " " << j+1 << '\n';
        }
    }
    cout.flush();
}