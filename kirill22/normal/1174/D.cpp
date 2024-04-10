#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    set<int> a, b;
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    int tmp;
    if(m == 1 && n == 1){
        cout << 0;
        return 0;
    }
    else if(m == 1){
        ans.push_back(2);
    a.insert(0);
    a.insert(2);
    b.insert(m);
    b.insert(2 ^ m);
    tmp = 2;
    }
    else{
    ans.push_back(1);
    a.insert(0);
    a.insert(1);
    b.insert(m);
    b.insert(1 ^ m);
    tmp = 1;
    }
    while(true){
        int ansi = -1;
        for(int i = 1;i < (1 << n);i++){
            int x = tmp ^ i;
            if(b.find(x) == b.end() && a.find(x) == a.end()){
                ansi = i;
                break;
            }
        }
        if(ansi == -1){
            break;
        }
        tmp = tmp ^ ansi;
        a.insert(tmp);
        b.insert(tmp ^ m);
        ans.push_back(ansi);
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
}