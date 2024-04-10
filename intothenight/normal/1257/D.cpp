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
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
mt19937 rnd(time(0));

template<class T, class BO>
struct sparse: vector<vector<T>>{
	int N, lg;
	vector<int> log;
	BO bin_op;
	sparse(){}
	sparse(const vector<T> &arr, BO bin_op):
		N(arr.size()), lg(ceil(log2(N))), bin_op(bin_op), log(N + 1){
		this->resize(N, vector<T>(lg + 1));
		for(int i = 2; i <= N; i ++){
			log[i] = log[i / 2] + 1;
		}
		for(int i = 0; i < N; i ++){
			(*this)[i][0] = arr[i];
		}
		for(int j = 1; j <= lg; j ++){
			for(int i = 0; i + (1 << j) <= N; i ++){
				(*this)[i][j] = bin_op((*this)[i][j - 1], (*this)[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	T query(int l, int r){
		int t = log[r - l];
		return bin_op((*this)[l][t], (*this)[r - (1 << t)][t]);
	}
	sparse operator=(const sparse &otr){
		N = otr.N, lg = otr.lg, log = otr.log;
		bin_op = otr.bin_op;
		this->resize(N, vector<T>(lg + 1));
		for(int i = 0; i < N; i ++){
			for(int j = 1; j <= lg; j ++){
				(*this)[i][j] = otr[i][j];
			}
		}
		return *this;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		cin >> n;
		vi a(n);
		cin >> a;
		sparse tb(a, [](int x, int y){return max(x, y);});
		int m;
		cin >> m;
		vector<pii> temp(m);
		cin >> temp;
		sort(all(temp));
		vector<pii> h;
		for(auto [p, s]: temp){
			while(!h.empty() && h.back().second <= s){
				h.pop_back();
			}
			h.push_back({p, s});
		}
		if(tb.query(0, n) > h.back().first){
			cout << "-1\n";
			continue;
		}
		int res = 0;
		for(int i = 0; i < n; res ++){
			int l = 1, r = n + 1 - i;
			while(r - l > 1){
				int m = l + r >> 1;
				auto t = lower_bound(all(h), pii{tb.query(i, i + m), 0});
				if(t->second >= m){
					l = m;
				}
				else{
					r = m;
				}
			}
			i += l;
		}
		cout << res << "\n";
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\                                    //
//           +++`+``+`+`++++        ///`````````````````````````````\                              //
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