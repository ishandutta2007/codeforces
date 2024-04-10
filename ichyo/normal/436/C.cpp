#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int distance(const string& s, const string& t){
    assert(s.size() == t.size());
    int res = 0;
    REP(i, s.size()){
        if(s[i] == t[i]) {
        } else {
            res++;
        }
    }
    return res;
}

int main(){
    int H, W, K, C;
    while(cin >> H >> W >> K >> C) {
        static int d[1000][1000] = {};
        vector<string> str(K);
        REP(i, K) {
            REP(y, H) {
                string tmp;
                cin >> tmp;
                str[i] += tmp;
            }
        }
        for(int i = 0; i < K; i++){
            for(int j = i + 1; j < K; j++){
                d[i][j] = d[j][i] = distance(str[i], str[j]) * C;
            }
        }
        typedef tuple<int, int, int> T;
        priority_queue<T, vector<T>, greater<T>> que;
        vector<int> res(K, H * W);
        REP(i, K) {
            que.push(T(H * W, -1, i));
        }
        int sum = 0;
        vector<pair<int, int>> use;
        vector<bool> used(K);
        while(!que.empty()){
            T t = que.top(); que.pop();
            int c = get<0>(t);
            int from = get<1>(t);
            int v = get<2>(t);
            if(used[v]) continue;
            used[v] = true;
            sum += c;
            use.push_back(make_pair(v + 1, from + 1));
            for(int nv = 0; nv < K; nv++) if(nv != v) {
                if(res[nv] > d[v][nv]) {
                    res[nv] = d[v][nv];
                    que.push(T(res[nv], v, nv));
                }
            }
        }
        cout << sum << endl;
        REP(i, use.size()){
            cout << use[i].first << " " << use[i].second << endl;
        }
    }
    return 0;
}