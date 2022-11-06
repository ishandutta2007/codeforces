#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==1){
            cout << "YES\n";
            for(int i = 1; i<=n; i++){
                cout << i << "\n";
            }
            continue;
        }
        if(n%2==1){
            cout << "NO\n";
            continue;
        }
        queue<int>q;
        queue<int>q2;
        for(int i = 1; i<=n*k; i++){
            if(i%2==1){
                q.push(i);
            }
            else{
                q2.push(i);
            }
        }
        cout << "YES\n";
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<k; j++){
                if(i%2==1){
                    cout << q.front() << " ";
                    q.pop();
                }
                else{
                    cout << q2.front() << " ";
                    q2.pop();
                }
            }
            cout << "\n";
        }
    }
    return 0;
}