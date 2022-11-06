#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            vector<char>arr(2*n);
            for(int j = 0; j<2*n; j++){
                if(j<i+1){
                    arr[j] = '(';
                }
                else if(j<2*(i+1)){
                    arr[j] = ')';
                }
                else if(j%2==0){
                    arr[j] = '(';
                }
                else{
                    arr[j] = ')';
                }
                cout << arr[j];
            }
            cout << "\n";
            
        }
    }
	return 0;
}