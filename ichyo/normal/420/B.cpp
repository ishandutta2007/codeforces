#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
vector<int> solve(vector<int> state, vector<string> op, vector<int> id){
    int n = state.size();
    int m = op.size();

    set<int> ok;
    int cur = 0;
    REP(i, n) if(state[i]) cur++;


    if(cur > 0){
        REP(i, n) if(state[i]) ok.insert(i);
    }else{
        REP(i, n) ok.insert(i);
    }

    // REP(i, n) cout << state[i] << " "; cout << endl;

    for(int i = 0; i < m; i++){
        if(op[i] == "+"){
            assert(!state[id[i]]);
            cur++;
            state[id[i]] = true;
            if(cur == 1){
                set<int> nok;
                if(ok.count(id[i])) nok.insert(id[i]);
                ok = nok;
            }
        }else{
            assert(state[id[i]]);
            cur--;
            state[id[i]] = false;
            if(cur > 0){
                ok.erase(id[i]);
            }
        }
    }

    vector<int> ans(ok.begin(), ok.end());
    return ans;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<string> op(m);
        vector<int> id(m);
        REP(i, m) cin >> op[i] >> id[i];
        REP(i, m) id[i] --;
        vector<int> state(n, -1);
        for(int i = m - 1; i >= 0; i--){
            if(op[i] == "-"){
                state[id[i]] = 1;
            }else{
                state[id[i]] = 0;
            }
        }

        vector<int> s1 = state;
        vector<int> s2 = state;

        REP(i, s1.size()) if(s1[i] == -1) s1[i] = 0;
        REP(i, s2.size()) if(s2[i] == -1) s2[i] = 1;

        set<int> ans;
        vector<int> a1 = solve(s1, op, id);
        vector<int> a2 = solve(s2, op, id);
        for(int a : a1) ans.insert(a);
        for(int a : a2) ans.insert(a);
        cout << ans.size() << endl;
        vector<int> ansv(ans.begin(), ans.end());
        for(int i = 0; i < ansv.size(); i++){
            cout << ansv[i] + 1;
            if(i == ansv.size() - 1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}