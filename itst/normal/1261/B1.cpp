#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int N , Q , ans[_] , seq[_];
vector < pair < int , int > > qry[_] , val;

int sz[_ << 2];
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void ins(int x , int l , int r , int t){++sz[x]; if(l != r) mid >= t ? ins(lch , l , mid , t) : ins(rch , mid + 1 , r , t);}
int find(int x , int l , int r , int s){
	if(l == r) return seq[l];
	return sz[lch] >= s ? find(lch , l , mid , s) : find(rch , mid + 1 , r , s - sz[lch]);
}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i){int x; cin >> x; val.push_back(make_pair(-x , i)); seq[i] = x;}
	cin >> Q; sort(val.begin() , val.end()); for(int i = 1 ; i <= Q ; ++i){int p , q; cin >> p >> q; qry[p].push_back(make_pair(q , i));}
	for(int i = 1 ; i <= N ; ++i){
		ins(1 , 1 , N , val[i - 1].second);
		for(int j = 0 ; j < qry[i].size() ; ++j)
			ans[qry[i][j].second] = find(1 , 1 , N , qry[i][j].first);
	}
	for(int i = 1 ; i <= Q ; ++i) printf("%d\n" , ans[i]);
	return 0;
}