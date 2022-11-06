#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if(m<n){
            cout << "No\n";
            continue;
        }
        if(n%2==0){
            if(m%2==0){
                cout << "Yes\n";
                for(int i = 0; i<n-2; i++){
                    cout << "1 ";
                }
                m-=n-2;
                cout << m/2 << " " << m/2 << "\n";
            }
            else{
                cout << "No\n";
            }
        }
        else{
            cout << "Yes\n";
            for(int i = 0; i<n-1; i++){
                cout << "1 ";
            }
            cout << m-(n-1) << "\n";
        }
    }
    return 0;
}