#include <iostream>
#include <vector>
using namespace std;
const int mxN = 1e5;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        int sum  = 0, mn = 1e8, num=0;
        bool zero=false;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                int cur; cin >> cur;
                if(cur<0) {
                    num++;
                    mn = min(-cur,mn);
                    sum-=cur;
                } else if(cur==0){
                    zero = true;
                } else {
                    mn = min(cur,mn);
                    sum+=cur;
                }
            }
        }
        if(zero or num%2==0) cout << sum << endl;
        else cout << sum-2*mn << endl;
    }
}