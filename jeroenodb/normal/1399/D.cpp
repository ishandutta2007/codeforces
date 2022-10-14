#include <iostream>
#include <string>
#include <stack>

using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 2e5;
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans[mxN];
		stack<int> zero, one;
		int cnt=1;
		for(int i=0;i<n;++i) {
			if(s[i]=='1') {
				if(zero.empty()) {
					ans[i] = cnt++;
				} else {
					ans[i] = zero.top();
					zero.pop();
				}
				one.push(ans[i]);
			} else {
				if(one.empty()) {
					ans[i] = cnt++;
				} else {
					ans[i] = one.top();
					one.pop();
				}
				zero.push(ans[i]);
			}
		}

		cout << cnt-1 << endl;
		for(int i=0;i<n;++i) cout << ans[i] << ' ';

		cout << endl;


	}
}