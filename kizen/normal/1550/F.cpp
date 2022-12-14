#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

struct Dsu2{
    int n;
    vector<int> pr, l, r, rk;
    Dsu2(int N):n(N){
        pr.resize(n); l.resize(n), r.resize(n);
        rk.resize(n);
        for(int i = 0; i < n; ++i) pr[i] = l[i] = r[i] = i, rk[i] = 1;
    }
    inline int get(int x){
        return x == pr[x] ? x : pr[x] = get(pr[x]);
    }
    inline bool unite(int x, int y){
        x = get(x), y = get(y);
        if(x != y){
        	if(rk[x] < rk[y]) swap(x, y);
        	rk[x] += rk[y];
            pr[y] = x;
            umi(l[x], l[y]), uma(r[x], r[y]);
            return true;
        }
        return false;
    }
}lr((int)2e5 + 4);

int n;

struct Dsu{
    int n;
    vector<int> pr, rk;
    Dsu(int N):n(N){
        pr.resize(n), rk.resize(n);
        for(int i = 0; i < n; ++i) pr[i] = i, rk[i] = 1;
    }
    inline int get(int x){
        return x == pr[x] ? x : pr[x] = get(pr[x]);
    }
    inline bool unite(int x, int y){
        x = get(x), y = get(y);
        if(x != y){
            if(rk[x] < rk[y]) swap(x, y);
            pr[y] = x, rk[x] += rk[y];
            return true;
        }
        return false;
    }
};

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q, s, d; cin >> n >> q >> s >> d; --s;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<vector<int>> que(q, vector<int>(3));
	for(int i = 0; i < q; ++i){
		cin >> que[i][0] >> que[i][1]; --que[i][0];
		que[i][2] = i;
	}
	sort(que.begin(), que.end(), [&](vector<int>&x, vector<int>&y){return x[1] < y[1];});
	priority_queue<vector<int>> pq;
	Dsu gr(n);
	auto upd = [&](int x)->void{
		int p = lower_bound(a.begin(), a.end(), a[x] + d) - a.begin();
		if(p < n){
			while(true){
            	int q = lr.get(p), cnt = 0;
            	if(lr.l[q] && gr.get(q) == gr.get(lr.l[q] - 1)) cnt += (int)lr.unite(lr.l[q] - 1, q);
            	if(lr.r[q] + 1 < n && gr.get(q) == gr.get(lr.r[q] + 1)) cnt += (int)lr.unite(lr.r[q] + 1, q);
            	if(!cnt) break;
            }
			if(gr.get(p) == gr.get(x)) p = lr.r[lr.get(p)] + 1;
			if(p < n){
				pq.push({-abs(a[p] - a[x] - d), x, p});
			}
		}
		--p;
		if(p >= 0){
			while(true){
            	int q = lr.get(p), cnt = 0;
            	if(lr.l[q] && gr.get(q) == gr.get(lr.l[q] - 1)) cnt += lr.unite(lr.l[q] - 1, q);
            	if(lr.r[q] + 1 < n && gr.get(q) == gr.get(lr.r[q] + 1)) cnt += lr.unite(lr.r[q] + 1, q);
            	if(!cnt) break;
            }
			if(gr.get(p) == gr.get(x)) p = lr.l[lr.get(p)] - 1;
			if(p >= 0 && x < p){
				pq.push({-abs(a[x] + d - a[p]), x, p});
			}
		}
	};
	for(int i = 0; i < n; ++i){
		upd(i);
	}
	vector<int> ans(q);
	for(int i = 0; i < q; ++i){
		while(!pq.empty() && -pq.top()[0] <= que[i][1]){
			int x = pq.top()[1], y = pq.top()[2];
			pq.pop();
			if(gr.unite(x, y)) upd(x);
		}
		ans[que[i][2]] = (gr.get(s) == gr.get(que[i][0]));
	}
	for(auto&i:ans){
		if(!i) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}