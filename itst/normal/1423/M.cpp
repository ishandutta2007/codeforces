#include<bits/stdc++.h>
using namespace std;

map < pair < int , int > , int > mem;
int qry(int p , int q){
	if(mem.find(make_pair(p , q)) != mem.end()) return mem[make_pair(p , q)];
	cout << "? " << p << ' ' << q << endl; int val; cin >> val; return mem[make_pair(p , q)] = val;
}
int N , M , L[1000003];

vector < int > reduce(vector < int > p1 , vector < int > p2){
	static int pre[1000003] , suf[1000003]; for(int i = 0 ; i < p2.size() ; ++i){pre[i] = i - 1; suf[i] = i + 1;}
	int cnt = p2.size() , pos = 0 , rk = 0 , hd = 0;
	auto del = [&](int p){
		if(pre[p] != -1) suf[pre[p]] = suf[p]; else hd = suf[p];
		pre[suf[p]] = pre[p]; --cnt;
	};
	while(cnt > p1.size())
		if(qry(p1[rk] , p2[pos]) <= qry(p1[rk] , p2[suf[pos]]))
			if(rk == p1.size() - 1) del(suf[pos]); else{pos = suf[pos]; ++rk;}
		else{pos = suf[pos]; del(pre[pos]); if(rk){pos = pre[pos]; --rk;}}
	p1.clear(); for(int i = hd ; i != p2.size() ; i = suf[i]) p1.push_back(p2[i]);
	return p1;
}

void solve(vector < int > p1 , vector < int > p2){
	p2 = reduce(p1 , p2); vector < int > pp;
	if(p1.size() == 1){L[p1[0]] = p2[0]; return;}
	for(int i = 0 ; i < p1.size() ; i += 2) pp.push_back(p1[i]);
	solve(pp , p2);
	for(int i = 1 ; i < p1.size() ; i += 2){
		int pl = lower_bound(p2.begin() , p2.end() , L[p1[i - 1]]) - p2.begin() ,
			pr = i + 1 < p1.size() ? lower_bound(p2.begin() , p2.end() , L[p1[i + 1]]) - p2.begin() : p2.size() - 1;
		L[p1[i]] = p2[pl]; for(int j = pl + 1 ; j <= pr ; ++j) if(qry(p1[i] , L[p1[i]]) > qry(p1[i] , p2[j])) L[p1[i]] = p2[j];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin >> N >> M; vector < int > pot1 , pot2;
	for(int i = 1 ; i <= N ; ++i) pot1.push_back(i);
	for(int i = 1 ; i <= M ; ++i) pot2.push_back(i);
	solve(pot1 , pot2); int mn = 1e9; for(int i = 1 ; i <= N ; ++i) mn = min(mn , qry(i , L[i]));
	cout << "! " << mn << endl; return 0;
}