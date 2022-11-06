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
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='0')continue;
            if(i<n-1){
                ans+=(s[i]-'0')+1;
            }
            else{
                ans+=(s[i]-'0');
            }
        }
        cout << ans << "\n";
    }
	return 0;
}