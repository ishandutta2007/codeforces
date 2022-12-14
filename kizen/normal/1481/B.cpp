#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i = 0; i < n; ++i){
            cin >> h[i];
        }
        if(k > 20000){
            cout << "-1\n";
            continue;
        }
        int f = 0, last;
        for(int i = 0; i < k; ++i){
            int did = 0;
            for(int j = 0; j < n - 1; ++j){
                if(h[j] < h[j + 1]){
                    ++h[j]; last = j;
                    did = 1;
                    break;
                }
            }
            if(!did){
                f = 1;
                break;
            }
        }
        if(f){
            cout << "-1\n";
        }
        else{
            cout << last + 1 << '\n';
        }
    }
    return 0;
}