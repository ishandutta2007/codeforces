#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef tuple<int, int, int> tpl;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << P.first << " " << P.second << "\n";
	return out;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
ostream &operator<<(ostream &out, const set<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const map<T1, T2> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rnd(time(0));
 
struct E{
	int v1, v2, w, ind;
	bool operator<(const E &otr){
		return w > otr.w;
	}
};
 
struct disjoint: vi{
	int n;
	vector<pii> rec;
	disjoint(int n): n(n){
		this->resize(n);
		iota(all((*this)), 0);
	}
	int insert(){
		n ++;
		this->push_back(this->size());
		return this->size() - 1;
	}
	int root(int u){
		rec.push_back({u, (*this)[u]});
		return (*this)[u] == u ? u : ((*this)[u] = root((*this)[u]));
	}
	void merge(int u, int v){
		(*this)[root(v)] = root(u);
	}
	void undo(){
		auto [u, c] = rec.back();
		(*this)[u] = c;
		rec.pop_back();
	}
};
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<E> edge(m);
	for(int i = 0; i < m; i ++){
		auto &[u, v, w, ind] = edge[i];
		cin >> u >> v >> w, u --, v --, ind = i;
	}
	vector<E> s(edge);
	sort(all(s));
	int q;
	cin >> q;
	vector<vector<pair<vi, int>>> query(5e5 + 1); // query[w]: list of query {{e_i}, query_ind}
	for(int i = 0; i < q; i ++){
		int k;
		cin >> k;
		map<int, vi> t;
		for(int j = 0; j < k; j ++){
			int e;
			cin >> e, e --;
			t[edge[e].w].push_back(e);
		}
		for(auto &[w, v]: t){
			query[w].push_back({v, i});
		}
	}
	vi res(q, true);
	disjoint dsu(n);
	for(int w = 1; w <= 500000; w ++){
		for(auto &[L, ind]: query[w]){
			if(res[ind]){
				int recover = dsu.rec.size();
				bool ok = true;
				for(auto e: L){
					int u = edge[e].v1, v = edge[e].v2;
					if(dsu.root(u) == dsu.root(v)){
						ok = false;
						break;
					}
					dsu.merge(u, v);
				}
				if(!ok){
					res[ind] = false;
				}
				while(dsu.rec.size() != recover){
					dsu.undo();
				}
			}
		}
		while(!s.empty() && s.back().w == w){
			dsu.merge(s.back().v1, s.back().v2);
			s.pop_back();
		}
	}
	for(auto x: res){
		x ? cout << "YES\n" : cout << "NO\n";
	}
	return 0;
}
 
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\                                     //
//           +++`+``+`+`++++        ///`````````````````````````````\                               //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                            //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                         //
//             +++`++`+``+///```````````|```````````````````````````````````\                       //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                      //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                     //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                   //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                  //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                 //
//       /\___|__//`|``|```````|`    |      ``:|````````|:```````|```````|```|`````|                //
//      /     /  /``|``|``````|/     |        :|     ```:|```````|```````|``++````++                //
//     /     / //```|``|``````|      |        |:        :|    ```|```````|```++``++`\               //
//     |    /  /````|``|``````/    _.::::.    |          |      |    ````|```|`++`\`|               //
//     |   /   |````|``|`````|            `                    |       ``|```++``++`|               //
//     |  /    |````|``|`````|                                 :         |``++````++|               //
//     | /     /````|``|`````|                              _.-:::.      |..`|``.`|.|               //
//     |/     /`````|``|`````|                                     `     |```|````|`|               //
//    /|      |`````|``|`````|                    :'                    .|```|````|.|               //
//   / |      |`````|``|`````|                                         /|-|``|````|`|               //
//  /  |      |`````|```\````|                                        / ||```|````|``\              //
// /   |      |`````|````|```|::                                    /_| ||```|````|``|              //
//            |`````|````|```|:|:.        `.._                    .\___/:|```|````|``|              //
//            |`````\````|```|:|::-          ``:::....           -:|:|:::|```|````|``|              //
//            |``````|```|```|:|::`|.                          .:::|:|:::|```|````|``|              //
//             \`````|```|```|:|::/|--.                     .`:|:::|:|:::/```|````|``|              //
//              |````|```|```\:|:|:|-----             _..-:|:|:|:::|:|::|````|````|`/               //
//              |````|```|````\|:|:|-------.____.....------|/::|:::|:|::|````|````|`|               //
//              |````|```|\````\:|/\___________    ________/\--\:::|:|::|````/````|`|               //
//              |````\```| \```|:/-------------\  /----------\``\::|:|::|```/`````|`|               //
//              |`````|``|  \``|/---------------\/------------\_________|```|`````|`|               //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                        Created by Aeren                                          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////