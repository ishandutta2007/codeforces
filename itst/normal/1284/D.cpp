#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7;
struct seg{
	int sa , sb , ta , tb;
	friend bool operator <(seg p , seg q){return p.sa < q.sa;}
}now[_]; int N;

#define int long long
namespace segt{
	bool val[_ * 30] , mrk[_ * 30]; int lch[_ * 30] , rch[_ * 30] , cnt;
	
	int alloc(){++cnt; val[cnt] = mrk[cnt] = 0; lch[cnt] = rch[cnt] = 0; return cnt;}
	
#define mid ((l + r) >> 1)
	
	void modify(int &x , int l , int r , int L , int R , int v){
		if(!x) x = alloc();
		if(l >= L && r <= R){mrk[x] = val[x] = 1; return;}
		if(mid >= L) modify(lch[x] , l , mid , L , R , v);
		if(mid < R) modify(rch[x] , mid + 1 , r , L , R , v);
		val[x] = val[lch[x]] | val[rch[x]];
	}

	bool qry(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return val[x];
		if(mrk[x]) return 1;
		if(!x) return 0;
		if(mid >= L && qry(lch[x] , l , mid , L , R)) return 1;
		return mid < R && qry(rch[x] , mid + 1 , r , L , R);
	}
}using namespace segt;

signed main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> now[i].sa >> now[i].sb >> now[i].ta >> now[i].tb;
	vector < int > pot;
	for(int i = 1 ; i <= N ; ++i){pot.push_back(now[i].sa); pot.push_back(now[i].sb);}
	sort(pot.begin() , pot.end()); pot.resize(unique(pot.begin() , pot.end()) - pot.begin());
	for(int i = 1 ; i <= N ; ++i){
		now[i].sa = lower_bound(pot.begin() , pot.end() , now[i].sa) - pot.begin();
		now[i].sb = lower_bound(pot.begin() , pot.end() , now[i].sb) - pot.begin();
	}

	pot.clear();
	for(int i = 1 ; i <= N ; ++i){pot.push_back(now[i].ta); pot.push_back(now[i].tb);}
	sort(pot.begin() , pot.end()); pot.resize(unique(pot.begin() , pot.end()) - pot.begin());
	for(int i = 1 ; i <= N ; ++i){
		now[i].ta = lower_bound(pot.begin() , pot.end() , now[i].ta) - pot.begin();
		now[i].tb = lower_bound(pot.begin() , pot.end() , now[i].tb) - pot.begin();
	}
	
	priority_queue < pair < int , int > > q;
	sort(now + 1 , now + N + 1); int rt = 0;
	for(int i = 1 , pi ; i <= N ; i = pi){
		pi = i;
		while(!q.empty() && -q.top().first < now[i].sa){
			int id = q.top().second; q.pop();
			segt::modify(rt , 0 , 2 * N , now[id].ta , now[id].tb , 1);
		}
		while(pi <= N && now[pi].sa == now[i].sa){
			if(segt::qry(rt , 0 , 2 * N , now[pi].ta , now[pi].tb)){cout << "NO"; return 0;}
			q.push(make_pair(-now[pi].sb , pi)); ++pi;
		}
	}
	for(int i = 1 ; i <= N ; ++i){swap(now[i].sa , now[i].ta); swap(now[i].sb , now[i].tb);}
	sort(now + 1 , now + N + 1); rt = 0; while(!q.empty()) q.pop();
	segt::cnt = 0;
	for(int i = 1 , pi ; i <= N ; i = pi){
		pi = i;
		while(!q.empty() && -q.top().first < now[i].sa){
			int id = q.top().second; q.pop();
			segt::modify(rt , 0 , 2 * N , now[id].ta , now[id].tb , 1);
		}
		while(pi <= N && now[pi].sa == now[i].sa){
			if(segt::qry(rt , 0 , 2 * N , now[pi].ta , now[pi].tb)){cout << "NO"; return 0;}
			q.push(make_pair(-now[pi].sb , pi)); ++pi;
		}
	}
	cout << "YES";
	return 0;
}