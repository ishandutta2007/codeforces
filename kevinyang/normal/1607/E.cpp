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
        string s;
        cin >> s;
        int left = 0; int right = 0; int up = 0; int down = 0;
        int ml = 0; int mr = 0; int mu = 0; int md = 0;
        int x = 1; int y = 1;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='L'){
                left++; right--;
            }
            if(s[i]=='R'){
                right++; left--;
            }
            if(s[i]=='U'){
                up++; down--;
            }
            if(s[i]=='D'){
                down++; up--;
            }
            ml = max(ml,left); mr = max(mr,right);
            mu = max(mu,up); md = max(md,down);
            if(ml+mr>=m)break;
            if(mu+md>=n)break;
            y = ml+1;
            x = mu+1;
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}