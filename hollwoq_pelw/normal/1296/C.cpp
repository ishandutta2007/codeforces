#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n;
        cin >> n;
        int a = -1, b = -1, ans = -1;
        int y=0 , x=0;
        string s;
        cin >> s;
        map<pair<int,int>,int> mp;
        mp[{0, 0}] = 0;
        for (int id = 0; id < n; id++){
            if (s[id]=='U') y ++;
            if (s[id]=='D') y --;
            if (s[id]=='L') x --;
            if (s[id]=='R') x ++;
            if (mp.count({x,y})){
                if (ans == -1 || id+1-mp[{x,y}] < ans){
                    ans = id+1-mp[{x,y}];
                    a = mp[{x,y}];
                    b = id+1;
                }
            }
            mp[{x,y}] = id+1;
        }
        if (ans == -1) cout << -1 << endl;
        else cout << a + 1 << ' ' << b << endl;
    }
    
    return 0;
}