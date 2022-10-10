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

template<class T, class BO1, class BO2>
struct fenwick{
	int n;
	vector<T> BIT;
	BO1 bin_op;
	BO2 inv_op;
	T id;
	fenwick(const vector<T> &arr, BO1 _bin_op, BO2 _inv_op, const T &_id): n(arr.size()), bin_op(_bin_op), inv_op(_inv_op), id(_id){
		BIT.resize(n + 1, id);
		for(int i = 0; i < n; i ++) update(i, arr[i]);
	}
	void update(int p, T val){
		for(p ++; p <= n; p += p & -p) BIT[p] = bin_op(BIT[p], val);
	}
	T query(int l, int r){
		return inv_op(sum(r - 1), sum(l - 1));
	}
	T sum(int p){
		T res = id;
		for(p ++; p > 0; p -= p & -p) res = bin_op(res, BIT[p]);
		return res;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, p;
	cin >> n >> p;
	vector<pii> nom(n);
	vector<vi> by(n);
	for(int i = 0; i < n; i ++){
		cin >> nom[i], nom[i].first --, nom[i].second --;
		if(nom[i].first > nom[i].second) swap(nom[i].first, nom[i].second);
		by[nom[i].first].push_back(i), by[nom[i].second].push_back(i);
	}
	vector<pii> deg(n), query(n);
	for(int i = 0; i < n; i ++){
		deg[i] = {by[i].size(), i};
		query[i] = {p - by[i].size(), i};
	}
	sort(all(deg)), sort(all(query));
	vi temp(n);
	fenwick tr(vi(n), plus<int>{}, minus<int>{}, 0);
	for(int i = n - 1; i >= 0; i --){
		auto [v, ind] = query[i];
		while(!deg.empty() && deg.back().first >= v){
			tr.update(deg.back().second, 1);
			deg.pop_back();
		}
		temp[ind] = tr.query(ind + 1, n);
	}
	ll res = 0;
	vi d(n);
	for(int i = 0; i < n; i ++) d[i] = by[i].size();
	for(int i = 0; i < n; i ++){
		vi used;
		int cnt = 0;
		for(auto j: by[i]){
			int k = nom[j].second;
			if(k > i && d[k] >= p - by[i].size()){
				d[k] --;
				used.push_back(k);
				if(d[k] == p - by[i].size() - 1){
					cnt ++;
				}
			}
		}
		for(auto j: used) d[j] ++;
		res += temp[i] - cnt;
	}
	cout << res;
	return 0;
}
/*
4 3
2 3
1 4
1 4
2 3

*/

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