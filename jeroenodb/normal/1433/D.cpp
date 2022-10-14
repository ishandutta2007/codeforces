#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin >> n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;++i) {
            int cur;cin >> cur;
            a[i] = {cur,i+1};
        }
        sort(a.begin(),a.end());
        bool first=true;
        int prev=0;
        for(int i=1;i<n;++i) {
            if(a[i].first==a[i-1].first) {
                continue;
            } else {
                if(first) {
                    cout << "YES\n";
                    for(int j=0;j<i;++j) {
                        cout << a[i].second << ' ' << a[j].second << endl;
                    }
                    prev= i+1;
                    first = false;
                } else {
                    for(int j=prev;j<i;++j) {
                        cout << a[0].second << ' ' << a[j].second << endl;
                    }
                    prev = i;
                   
                }
            }
        }
        if(first == true) {
            cout << "NO\n";
            continue;
        } 
        for(int j=prev;j<n;++j) {
            cout << a[0].second << ' ' << a[j].second << endl;
        }
            
        
        




        
        
    }
}