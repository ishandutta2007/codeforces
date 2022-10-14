#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin >> n;
        int mx,cand=0;
        vector<int> a(n);
        bool different = false;
        for(int i=0;i<n;++i) {
            cin >> a[i];
            if(i==0) mx = a[i];
            else {
                different|= mx!=a[i];
                mx = max(mx,a[i]);
            }
        }
        //cout << "ans: ";
        if(!different) {
            cout << "-1\n";
            continue;
        }
        for(int i=0;i<n;++i) {
            if(a[i] == mx and ((i>0 and a[i-1] != mx ) or (i+1<n and a[i+1] != mx))) {
                cout << i+1 << endl;
                break;
            }
        }
        
        
    }
}