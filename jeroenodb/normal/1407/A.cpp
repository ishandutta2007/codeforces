#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    cout << #a ": " << (a) << ' ';

void solve() {
    int n;
    cin >> n;
    int sum=0;
    for(int i=0;i<n;++i) {
        int cur; cin >> cur;
        sum+=cur;
    }

    if(sum>n/2) {
        int limit = n/2;
        if(limit%2==1) limit++;
        cout << limit << '\n';
        for(int i=0;i<limit;++i) {
            cout << "1 ";
        }
    } else {
        cout << n/2 << '\n';
        for(int i=0;i<n/2;++i) {
            cout << "0 ";
        }
    } 
    cout << '\n';


}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}