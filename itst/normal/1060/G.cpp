#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
const int _ = 1e5 + 7;
int N , M , A[_] , C , ans[_] , id[_] , T[_]; struct query{int x , k , id;}Q[_];
tree<int , null_type , less < int > , rb_tree_tag , tree_order_statistics_node_update> tr;

signed main(){
	ios::sync_with_stdio(0); cin >> N >> M; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = 1 ; i <= M ; ++i){cin >> Q[i].x >> Q[i].k; Q[i].id = i;}
	sort(Q + 1 , Q + M + 1 , [&](query p , query q){return p.x < q.x;});
	for(int i = 1 ; i <= N ; ++i) tr.insert(i);
	int l = 2e15 , tm = 0; int p1 = N , p2 = M;
	while(p1 && p2){
		int t = (l - max(A[p1] , Q[p2].x) + tr.size() - 1) / tr.size(); tm += t; l -= tr.size() * t;
		while(p2 && Q[p2].x >= l){Q[p2].x = *tr.find_by_order(Q[p2].x - l); Q[p2].k = tm - Q[p2].k; --p2;}
		while(p1 && A[p1] >= l) tr.erase(tr.find_by_order(A[p1--] - l));
		l -= tr.size(); ++tm;
	}
	while(p2){ans[Q[p2].id] = Q[p2].x; Q[p2].id = 0; --p2;}
	sort(Q + 1 , Q + M + 1 , [&](query p , query q){return p.k < q.k;});
	l = 2e15; tm = 0; p1 = N; p2 = 1; for(int i = 1 ; i <= N ; ++i) tr.insert(i);
	
	while(p1 && p2){
		int t = (l - A[p1] + tr.size() - 1) / tr.size(); tm += t;
		while(p2 <= M && Q[p2].k <= tm){ans[Q[p2].id] = l - tr.size() * (Q[p2].k - (tm - t)) + tr.order_of_key(Q[p2].x); ++p2;}
		l -= tr.size() * t; while(p1 && A[p1] >= l) tr.erase(tr.find_by_order(A[p1--] - l));
		l -= tr.size(); ++tm;
	}
	for(int i = 1 ; i <= M ; ++i) printf("%lld\n" , ans[i]);
	return 0;
}