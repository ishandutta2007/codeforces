#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

#define sz(x) (int)x.size()
const int _ = 1e5 + 7;
struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , val[_] , cntEd , N , Q , T , ans;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int sz[_] , fa[_] , dep[_] , top[_] , son[_];
struct data{
	struct block{
		vector < int > suf , list_size; //list
		vector < pair < int , int > > val; int mrk , plc , sz , num;
		void build_by_sorted_data(vector < pair < int , int > > &pos){
			val.clear();
			for(int i = 0 ; i < sz ; ++i){
				if(!i || pos[i].first != pos[i - 1].first) val.push_back(make_pair(pos[i].first , -1));
				int p = pos[i].second , &q = val.back().second; suf[p] = q; q = p;
				list_size[p] = (~suf[p] ? list_size[suf[p]] : 0) + 1;
			}
			num = mrk = 0; plc = sz(val); while(plc && val[plc - 1].first > 0) num += list_size[val[--plc].second];
		}
		
		void build(vector < int > pot){
			suf.resize(sz = sz(pot)); list_size = suf; vector < pair < int , int > > pos;
			for(int i = 0 ; i < sz ; ++i) pos.push_back(make_pair(pot[i] , i));
			sort(pos.begin() , pos.end()); build_by_sorted_data(pos);
		}

		void mdf(int l , int r , int v){
			if(!l && r + 1 == sz && (v == 1 || v == -1))
				if(v == 1){++mrk; if(plc && val[plc - 1].first + mrk > 0) num += list_size[val[--plc].second];}
				else{--mrk; if(plc != sz(val) && val[plc].first + mrk <= 0) num -= list_size[val[plc++].second];}
			else{
				static vector < pair < int , int > > x , y , ans; x.clear(); y.clear(); ans.clear();
				for(auto p : val)
					for(int q = p.second ; ~q ; q = suf[q])
						(q >= l && q <= r ? x : y).push_back(make_pair(p.first + mrk , q));
				for(auto &t : x) t.first += v;
				int px = 0 , py = 0;
				while(px < sz(x) || py < sz(y))
					if(px != sz(x) && (py == sz(y) || x[px] < y[py])) ans.push_back(x[px++]);
					else ans.push_back(y[py++]);
				build_by_sorted_data(ans);
			}
		}
	}; vector < block > blc; int len , num , sz , rt;
	
	void init(int x){
		rt = x; vector < int > arr; while(x){arr.push_back(val[x]); x = son[x];}
		len = sz(arr); sz = sqrt(len / 5) + 1;
		for(int i = 0 ; i < len ; i += sz){
			block tmp; tmp.build(vector < int > (arr.begin() + i , arr.begin() + min(sz(arr) , i + sz)));
			blc.push_back(tmp); num += tmp.num;
		}
		ans += num;
	}

	void mdf_block(int p , int l , int r , int v){num -= blc[p].num; blc[p].mdf(l , r , v); num += blc[p].num;}
	
	void mdf(int l , int r , int v){
		int bell = l / sz , belr = r / sz; ans -= num;
		if(bell == belr) mdf_block(bell , l - bell * sz , r - bell * sz , v);
		else{
			for(int i = bell + 1 ; i < belr ; ++i) mdf_block(i , 0 , blc[i].sz - 1 , v);
			mdf_block(bell , l - bell * sz , blc[bell].sz - 1 , v); mdf_block(belr , 0 , r - belr * sz , v);
		}
		ans += num;
	}
}now[_];

void dfs1(int x , int p){
	fa[x] = p; dep[x] = dep[p] + 1; sz[x] = 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){dfs1(Ed[i].end , x); sz[x] += sz[Ed[i].end]; son[x] = sz[son[x]] < sz[Ed[i].end] ? Ed[i].end : son[x];}
}

void dfs2(int x , int t){
	top[x] = t; if(x == t) now[x].init(x);
	if(son[x]){dfs2(son[x] , t); for(int i = head[x] ; i ; i = Ed[i].upEd) if(Ed[i].end != fa[x] && Ed[i].end != son[x]) dfs2(Ed[i].end , Ed[i].end);}
}

void mdf(int x , int y , int v){
	int tx = top[x] , ty = top[y];
	while(tx != ty){
		if(dep[tx] < dep[ty]){swap(tx , ty); swap(x , y);}
		now[tx].mdf(0 , dep[x] - dep[tx] , v); x = fa[tx]; tx = top[x];
	}
	now[tx].mdf(min(dep[x] , dep[y]) - dep[tx] , max(dep[x] , dep[y]) - dep[tx] , v);
}

int main(){
	N = read(); Q = read();
	for(int i = 2 ; i <= N ; ++i){int p = read(); addEd(p , i); addEd(i , p);}
	for(int i = 1 ; i <= N ; ++i) val[i] = -read();
	dfs1(1 , 0); dfs2(1 , 1);
	while(Q--){
		int tmp = read() , x = abs(tmp); if(tmp < 0){mdf(x , 1 , -1); mdf(x , x , 1e9);} else{mdf(x , 1 , 1); mdf(x , x , -1e9);}
		printf("%d " , ans);
	}
	return 0;
}