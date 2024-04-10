#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int D, S;
    cin >> D >> S;
    vector<int> rest(D);
    vector<int> ans(D);
    REP(i, D){
        int a, b;
        cin >> a >> b;
        S -= a;
        rest[i] = b - a;
        ans[i] = a;
    }
    if(S < 0){
        cout << "NO" << endl;
    }else{
        REP(i, D){
            int p = min(S, rest[i]);
            ans[i] += p;
            S -= p;
        }
        if(S == 0){
            cout << "YES" << endl;
            REP(i, D){
                cout << ans[i];
                if(i == D - 1) cout << endl;
                else cout << " ";
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}