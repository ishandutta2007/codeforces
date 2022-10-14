#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN=1e5;
void solve() {
    int n;
    cin >> n;
    int a[mxN];
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    if(n==1) {
        cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0\n"; return;
    }
    cout << "1 " << n << endl;
    for(int i=0;i<n;++i) {
        if(i==0) cout << 0 << ' ';
        else cout << (long long)(-n)*a[i] << ' ';
    } cout << endl;
    cout << "1 1\n" << -a[0] << endl;
    cout << "2 " << n << endl;
    for(int i=1;i<n;++i) {
        cout << (long long)a[i]*(n-1) << ' ';
    } cout << endl;

}
int main() {

    solve();
}