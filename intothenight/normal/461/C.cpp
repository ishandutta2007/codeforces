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
using Tree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rnd(time(0));

template<class T = ll, class BO1 = function<T(T, T)>, class BO2 = function<T(T, T)>>
struct fenwick: vector<T>{
	int N;
	BO1 bin_op;
	BO2 inv_op;
	T id;
	fenwick(const vector<T> &arr, BO1 bin_op, BO2 inv_op, T id):
		N(arr.size()), bin_op(bin_op), inv_op(inv_op), id(id){
		this->resize(N + 1, id);
		for(int i = 0; i < N; i ++){
			update(i, arr[i]);
		}
	}
	void update(int p, T val){
		for(p ++; p <= N; p += p & -p){
			(*this)[p] = bin_op((*this)[p], val);
		}
	}
	T sum(int p){
		T res = id;
		for(p ++; p > 0; p -= p & -p){
			res = bin_op(res, (*this)[p]);
		}
		return res;
	}
	T query(int l, int r){
		return inv_op(sum(r - 1), sum(l - 1));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	fenwick tr(vi(n, 1), plus<>{}, minus<>{}, 0);
	int s = 0, t = n;
	while(q --){
		int type, l = abs(s - t);
		cin >> type;
		if(type == 1){
			int p;
			cin >> p;
			if(2 * p < l){
				if(s < t){
					for(int i = s + p - 1, j = s + p; i >= s && j < t; i --, j ++){
						tr.update(j, tr.query(i, i + 1));
					}
					s = s + p;
				}
				else{
					for(int i = s - p, j = s - p + 1; i > t && j <= s; i --, j ++){
						tr.update(i, tr.query(j, j + 1));
					}
					s = s - p;
				}
			}
			else{
				if(s < t){
					for(int i = s + p - 1, j = s + p; i >= s && j < t; i --, j ++){
						tr.update(i, tr.query(j, j + 1));
					}
					t = s - 1;
					s = s + p - 1;
				}
				else{
					for(int i = s - p, j = s - p + 1; i > t && j <= s; i --, j ++){
						tr.update(j, tr.query(i, i + 1));
					}
					t = s + 1;
					s = s - p + 1;
				}
			}
		}
		else{
			int l, r;
			cin >> l >> r;
			if(s < t){
				cout << tr.query(s + l, s + r) << "\n";
			}
			else{
				cout << tr.query(s - r + 1, s - l + 1) << "\n";
			}
		}
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