#include<bits/stdc++.h>
using namespace std;

#define int long long
int N , W; struct thing{int sz , val , del , id;}; vector < thing > pot;

signed main(){
	ios::sync_with_stdio(0); cin >> N >> W;
	for(int i = 0 ; i < N ; ++i){
		int A , B; cin >> A >> B;
		if(2 * A <= B){pot.push_back((thing){1 , A , A , i}); pot.push_back((thing){1 , B - A , B - A , i});}
		else pot.push_back((thing){2 , B , B - A , i});
	}
	sort(pot.begin() , pot.end() , [&](thing p , thing q){return p.val * q.sz < q.val * p.sz || p.val * q.sz == q.val * p.sz && p.del > q.del;});
	int sum = 0 , cnt = 0; pair < int , string > ans(1e18 , ""); pair < int , int > del(0 , N); string cur(N , '0');
	for(int i = 0 ; i < pot.size() && cnt != W ; ++i)
		if(W - cnt >= 2 || pot[i].sz == 1){
			cnt += pot[i].sz; sum += pot[i].val;
			del = max(del , make_pair(pot[i].del , pot[i].id));
			cur[pot[i].id] += pot[i].sz;
		}
		else{
			pair < int , int > mna(pot[i].val - pot[i].del , pot[i].id);
			for(int j = i + 1 ; j < pot.size() ; ++j)
				mna = min(mna , make_pair(pot[j].sz == 1 ? pot[j].val : pot[j].val - pot[j].del , pot[j].id));
			++cur[mna.second]; ans = make_pair(sum + mna.first , cur); --cur[mna.second];
			if(del.first) --cur[del.second];
			cur[pot[i].id] += 2; ans = min(ans , make_pair(sum - del.first + pot[i].val , cur)); break;
		}
	if(cnt == W) ans = make_pair(sum , cur);
	cout << ans.first << endl << ans.second; return 0;
}