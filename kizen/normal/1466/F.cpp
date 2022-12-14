#include <bits/stdc++.h>

using namespace std;

struct dsu{
    int N;
    vector<int> pr, rk, all;
    dsu(){}
    dsu(int n):N(n){
        pr.resize(N), rk.resize(N), all.resize(N);
        for(int i = 0; i < N; ++i) pr[i] = i, rk[i] = 1, all[i] = 0;
    }
    inline int get(int x){
        return x == pr[x] ? x : pr[x] = get(pr[x]);
    }
    inline bool unite(int x, int y){
        x = get(x), y = get(y);
        if(x != y){
            if(rk[x] < rk[y]) swap(x, y);
            pr[y] = x, rk[x] += rk[y];
            all[x] |= all[y];
            return true;
        }
        return false;
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	dsu gr(M + 1);
	int MOD = (int)1e9 + 7;
	long long ans = 1;
	vector<int> use;
	for(int i = 0; i < N; ++i){
		int k; cin >> k;
		if(k == 1){
			int a; cin >> a;
			int val = gr.get(a);
			if(!gr.all[val]){
				use.push_back(i);
				gr.all[val] = 1;
			}
		}
		else{
			int a, b; cin >> a >> b;
			if((!gr.all[gr.get(a)] || !gr.all[gr.get(b)]) && gr.unite(a, b)){
				use.push_back(i);
			}
		}
	}
	vector<int> powt(M + 1);
	powt[0] = 1;
	for(int i = 1; i <= M; ++i){
		powt[i] = (powt[i - 1] << 1) % MOD;
	}
	for(int i = 1; i <= M; ++i){
		if(gr.get(i) == i){
			ans *= (long long)powt[gr.rk[i] - 1] * (gr.all[i] + 1); ans %= MOD;
		}
	}
	cout << ans << ' ' << (int)use.size() << '\n';
	for(auto&i:use){
		cout << i + 1 << ' ';
	}
	return 0;
}