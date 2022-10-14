#include <iostream>
#include <string>
#include <vector>


using namespace std;
#define D(a) \
    cout << #a ": " << (a) << ' ';
const int mxN = 3e5+1;
void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> real(k);
    bool impos=false;
    for(int i=0;i<n;++i) {
        int p = i%k;
        if(s[i]=='1') {
            if(real[p]==1) {
                impos = true;
                break;
            } 
            real[p]=2;
        } else if(s[i]=='0') {
            if(real[p]==2) {
                //cout << "overlapping false ";
                impos = true;
                break;
            } 
            real[p]=1;
        }
    }
    //for(int i:real) cout << i << ' ';
    if(impos) {cout << "NO\n";return;}
    int hist[3]={};
    for(int i=0;i<k;++i) {
        hist[real[i]]++;
    }
    //cout << hist[0] << ' ' << hist[1] << ' ' << hist[2] << ' ';
    if(hist[1]<=k/2 and hist[2] <= k/2) {
       cout << "YES\n";
    } else cout << "NO\n";

    

    

}
int main() {
	int T;
	cin >> T;
	for(int i=1;i<=T;++i) {
		solve();
	}
}