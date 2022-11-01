#include<bits/stdc++.h>
using namespace std;

#define pii pair < int , int >
const int _ = 2e5 + 7; int A[_] , B[_] , sum_q[_] , sum_v[_] , num[_] , N , M; pii dp[_];

#define find(x , v) (lower_bound(x.begin() , x.end() , v) - x.begin())
struct bit{
	pii arr[_]; int sz; bit(){memset(arr , -0x3f , sizeof(arr));}
#define lowbit(x) (x & -x)
	void mdf(int x , pii v){while(x <= sz && arr[x] < v){arr[x] = v; x += lowbit(x);}}
	pii qry(int x){pii mx = arr[0]; while(x){mx = max(mx , arr[x]); x -= lowbit(x);} return mx;}
	void clr(){memset(arr , -0x3f , sizeof(pii) * (sz + 1));}
}T1 , T2;

pii operator +(pii p , int q){return make_pair(p.first + q , p.second);}

void solve(int l , int r){
	if(l == r) return;
	int mid = (l + r) >> 1; solve(l , mid);
	vector < int > pos , pot; for(int i = l ; i <= mid ; ++i){pos.push_back(i); pot.push_back(sum_v[A[i]] - sum_q[i]);}
	for(int i = mid + 1 ; i <= r ; ++i){pos.push_back(i); pot.push_back(sum_v[A[i] - 1] - sum_q[i]);}
	sort(pos.begin() , pos.end() , [&](int p , int q){return A[p] < A[q] || A[p] == A[q] && p > q;});
	sort(pot.begin() , pot.end()); T1.sz = T2.sz = pot.size(); T1.clr(); T2.clr();
	for(auto t : pos)
		if(t <= mid){
			int p = find(pot , sum_v[A[t]] - sum_q[t]);
			T1.mdf(p + 1 , pii(dp[t].first - sum_q[t] , t)); T2.mdf(pot.size() - p , pii(dp[t].first - sum_v[A[t]] , t));
		}
		else{
			int p = find(pot , sum_v[A[t] - 1] - sum_q[t]);
			dp[t] = max(dp[t] , max(T1.qry(p + 1) + sum_q[t] + 1 , T2.qry(pot.size() - p) + sum_v[A[t] - 1] + 1));
		}
	solve(mid + 1 , r);
}

int main(){
	ios::sync_with_stdio(0); cin >> N; A[0] = -1;
	for(int i = 1 ; i <= N ; ++i){cin >> A[i]; if(A[i] == -1){--N; ++sum_q[i--];}}
	A[++N] = 1e9 + 1; cin >> M; for(int i = 1 ; i <= M ; ++i) cin >> B[i];

	vector < int > lsh; for(int i = 0 ; i <= N ; ++i) lsh.push_back(A[i]);
	for(int i = 1 ; i <= M ; ++i) lsh.push_back(B[i]);
	sort(lsh.begin() , lsh.end()); lsh.resize(unique(lsh.begin() , lsh.end()) - lsh.begin());
	for(int i = 0 ; i <= N ; ++i) A[i] = find(lsh , A[i]);
	for(int i = 1 ; i <= M ; ++i) ++num[find(lsh , B[i])];
	
	for(int i = 1 ; i < lsh.size() ; ++i) sum_v[i] = (bool)num[i] + sum_v[i - 1];
	for(int i = 1 ; i <= N ; ++i) sum_q[i] += sum_q[i - 1];
	solve(0 , N); vector < int > ans;
	for(int i = N ; i ; i = dp[i].second){
		int cur = A[i] - 1;
		for(int j = i ; j > dp[i].second ; --j){
			ans.push_back(lsh[A[j]]); sum_q[j] -= sum_q[j - 1];
			while(sum_q[j]--){
				while(!num[cur] && cur > A[dp[i].second]) --cur;
				if(cur == A[dp[i].second]) ans.push_back(-1);
				else{ans.push_back(lsh[cur]); --num[cur--];}
			}
		}
	}
	reverse(ans.begin() , ans.end()); ans.pop_back(); int cur = 0;
	for(auto &t : ans){if(t == -1){while(!num[cur]) ++cur; t = lsh[cur]; --num[cur];} cout << t << ' ';}
	
	return 0;
}