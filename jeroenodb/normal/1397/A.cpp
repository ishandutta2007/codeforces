#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)

void solve() {
    int n;
    cin >> n;
    int m[26]={};
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        for(char c:s) {
            m[c-'a']++;
        }
    }
    for(int i=0;i<26;++i) {
        if(m[i]%n!=0) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES" << endl;
}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}