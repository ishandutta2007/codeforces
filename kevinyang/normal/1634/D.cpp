#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x, int y, int z){
    cout << "? " << x << " " << y << " " << z << endl;
    int v;
    cin >> v;
    return v;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx = 0; int idx = 3;
        for(int i = 3; i<=n; i++){
            int v = f(1,2,i);
            if(v>mx){
                mx = v;
                idx = i;
            }
        }
        int idx2 = 3;
        if(idx==3){
            idx2++;
        }
        int mx2 = 0; int idx3 = 1;
        set<int>s;
        for(int i = 1; i<=n; i++){
            if(i==idx)continue;
            if(i==idx2)continue;
            int v = f(i,idx,idx2);
            s.insert(v);
            if(v>mx2){
                mx2 = v;
                idx3 = i;
            }
        }
        if(mx>mx2){
            cout << "! 1 2" << endl;
        }
        else if(s.size()==1){
            cout << "! " << idx << " " << idx2 << endl;
        }
        else{
            cout << "! " << idx << " " << idx3 << endl;
        }
    }
    return 0;
}