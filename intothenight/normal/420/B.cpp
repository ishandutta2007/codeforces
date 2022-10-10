#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

template<class T, class BO>
struct lazyfastseg{
	int n;
	vector<T> tree;
	BO bin_op;
	T id;
	lazyfastseg(const vector<T> &arr, BO _bin_op, const T &_id): n(arr.size()), bin_op(_bin_op), id(_id){
		tree.resize(n << 1, id);
		for(int i = 0; i < n; i ++){
			tree[i + n] = arr[i];
		}
		build();
	}
	lazyfastseg operator=(const lazyfastseg &target){
		n = target.n, tree = target.tree, bin_op = target.bin_op, id = target.id;
		return *this;
	}
	void build(){
		for(int i = n - 1; i > 0; i --){
			tree[i] = bin_op(tree[i << 1], tree[i << 1 | 1]);
		}
	}
	void update(int l, int r, T val){
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) tree[l ++] += val;
			if(r & 1) tree[-- r] += val;
		}
	}
	T query(int p){
		T res = id;
		for(p += n; p > 0; p >>= 1) res += tree[p];
		return res;
	}
	void push(){
		for(int i = 1; i < n; i ++){
			tree[i << 1] += tree[i];
			tree[i << 1 | 1] += tree[i];
			tree[i] = 0;
		}
	}
	void clear(){
		fill(all(tree), id);
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> log(n);
	lazyfastseg tr(vi(m + 1), plus<int>{}, 0);
	for(int t = 1; t <= m; t ++){
		char c;
		int k;
		cin >> c >> k, k --;
		if(c == '+'){
			log[k].push_back({t, 0});
		}
		else{
			if(log[k].empty()){
				log[k].push_back({0, t});
				tr.update(0, t, 1);
			}
			else{
				log[k].back() = {log[k].back().first, t};
				tr.update(log[k].back().first, t, 1);
			}
		}
	}
	for(auto &x: log){
		if(!x.empty() && !x.back().second){
			x.back().second = m + 1;
			tr.update(x.back().first, x.back().second, 1);
		}
	}
	tr.push();
	vi sum(m + 2);
	partial_sum(tr.tree.begin() + m + 1, tr.tree.end(), sum.begin() + 1);
	auto get_sum = [&](int l, int r){
		return sum[r] - sum[l];
	};
	vi res;
	for(int i = 0; i < n; i ++){
		bool ok = true;
		if(!log[i].empty()){
			if(get_sum(0, log[i].front().first)){
				continue;
			}
			if(get_sum(log[i].back().second, m + 1)){
				continue;
			}
			for(int j = 0; j < sz(log[i]) - 1; j ++){
				if(get_sum(log[i][j].second, log[i][j + 1].first)){
					ok = false;
					continue;
				}
			}
		}
		if(ok) res.push_back(i + 1);
	}
	cout << res.size() << "\n" << res;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\\                //
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