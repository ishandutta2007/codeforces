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
	    if(n%2==1){
	        cout << "3 1 2 ";
	        for(int i = 4; i<=n; i+=2){
	            cout << i+1 << " " << i << " ";
	        }
	        cout << "\n";
	    }
	    else{
	        for(int i = 1; i<=n; i+=2){
	            cout << i+1 << " " << i << " ";
	        }
	        cout << "\n";
	    }
	}
	return 0;
}