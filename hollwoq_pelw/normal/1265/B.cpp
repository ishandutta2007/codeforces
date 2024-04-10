#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,k;
        cin >> n;
        map<int,int> mp;
        for (int i = 1; i <= n; i++){
            cin >> k;
            mp[k] = i;
        }
        int lpos = mp[1], rpos = mp[1];
        string s = "";
        for (int i = 1; i <= n; i++){
            lpos = min(lpos, mp[i]);
            rpos = max(rpos, mp[i]);
            if (rpos-lpos+1==i) s += '1';
            else s += '0';
        }
        cout << s << endl;
    }
}