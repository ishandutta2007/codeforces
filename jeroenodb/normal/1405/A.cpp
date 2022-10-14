#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    cout << #a ": " << (a) << ' ';
void solve() {
    int n,a[101];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i=n-1;i>=0;--i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    

}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}