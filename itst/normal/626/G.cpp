#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define pli pair < ld , int >
const int _ = 2e5 + 7; int N , T , Q , cnt[_] , p[_] , l[_]; multiset < pli > Dec , Inc; ld ans;
ld incval(int id){return cnt[id] == l[id] ? -1e9 : p[id] * (1.0 * (cnt[id] + 1) / (cnt[id] + l[id] + 1) - 1.0 * cnt[id] / (cnt[id] + l[id]));}
ld decval(int id){return !cnt[id] ? -1e9 : p[id] * (1.0 * (cnt[id] - 1) / (cnt[id] + l[id] - 1) - 1.0 * cnt[id] / (cnt[id] + l[id]));}
void ins(int p){Dec.insert(pli(decval(p) , p)); Inc.insert(pli(incval(p) , p)); ans += 1.0 * ::p[p] * cnt[p] / (cnt[p] + l[p]);}
void del(int p){Dec.erase(pli(decval(p) , p)); Inc.erase(pli(incval(p) , p)); ans -= 1.0 * ::p[p] * cnt[p] / (cnt[p] + l[p]);}

int main(){
	ios::sync_with_stdio(0); cin >> N >> T >> Q;
	for(int i = 1 ; i <= N ; ++i){cin >> p[i];} for(int i = 1 ; i <= N ; ++i){cin >> l[i];} l[++N] = T;
	priority_queue < pair < ld , int > > q; for(int i = 1 ; i <= N ; ++i) q.push(make_pair(incval(i) , i));
	while(T--){int t = q.top().second; q.pop(); ++cnt[t]; q.push(make_pair(incval(t) , t));}
	for(int i = 1 ; i <= N ; ++i) ins(i);
	while(Q--){
		int p , r; cin >> r >> p; del(p); if((l[p] += (r == 2 ? -1 : 1)) < cnt[p]){--cnt[p]; del(N); ++cnt[N]; ins(N);} ins(p);
		while(Dec.rbegin()->first + Inc.rbegin()->first > 0){
			int p = Inc.rbegin()->second , q = Dec.rbegin()->second; del(p); del(q); ++cnt[p]; --cnt[q]; ins(p); ins(q);
		}
		cout << fixed << setprecision(10) << ans << '\n';
	}
	return 0;
}