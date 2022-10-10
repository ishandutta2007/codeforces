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
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

struct node{
	int cnt, min1, min2 = 2e9;
	node(){}
	node(int cnt, int min1, int min2): cnt(cnt), min1(min1), min2(min2){}
};

template<class T, class BO>
struct fastseg{
	int n;
	vector<T> arr;
	BO bin_op;
	T id;
	fastseg(const vector<T> &_arr, BO _bin_op, const T &_id): n(_arr.size()), bin_op(_bin_op), id(_id), arr(n << 1, _id){
		for(int i = 0; i < n; i ++) arr[i + n] = _arr[i];
		build();
	}
	fastseg(){}
	fastseg operator=(const fastseg &other){
		n = other.n, arr = other.arr, bin_op = other.bin_op, id = other.id;
		return *this;
	}
	void build(){
		for(int i = n - 1; i > 0; i --){
			arr[i] = bin_op(arr[i << 1], arr[i << 1 | 1]);
		}
	}
	void update(int p, T val){
		for(arr[p += n] = val; p > 1; p >>= 1){
			arr[p >> 1] = bin_op(arr[p], arr[p ^ 1]);
		}
	}
	T query(int l, int r){
		if(l >= r){
			return id;
		}
		T resl = id, resr = id;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = bin_op(resl, arr[l ++]);
			if(r & 1) resr = bin_op(arr[-- r], resr);
		}
		return bin_op(resl, resr);
	}
	void clear(){
		fill(arr.begin(), arr.end(), id);
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vi> a(9, vi(n));
	cin >> a[0];
	function<node(node, node)> op = [&](node x, node y){
		node res;
		res.cnt = x.cnt + y.cnt;
		if(x.min1 <= y.min1){
			res.min1 = x.min1;
			res.min2 = min({x.min2, y.min1, y.min2});
		}
		else{
			res.min1 = y.min1;
			res.min2 = min({x.min1, x.min2, y.min2});
		}
		return res;
	};
	vector<fastseg<node, function<node(node, node)>>> tr(9);
	for(int k = 0; k < 9; k ++){
		vector<node> d(n);
		for(int i = 0; i < n; i ++){
			if(k) a[k][i] = a[k - 1][i] / 10;
			if(a[k][i] % 10) d[i] = node(1, a[0][i], 2e9);
			else d[i] = node(0, 2e9, 2e9);
		}
		tr[k] = fastseg(d, op, node(0, 2e9, 2e9));
	}
	while(m --){
		int type, a, b;
		cin >> type >> a >> b;
		if(type == 1){
			int temp = b;
			for(int k = 0; k < 9; k ++, temp /= 10){
				if(temp % 10) tr[k].update(a - 1, node(1, b, 2e9));
				else tr[k].update(a - 1, node(0, 2e9, 2e9));
			}
		}
		else{
			int res = 2e9;
			for(int k = 0; k < 9; k ++){
				auto p = tr[k].query(a - 1, b);
				if(p.cnt >= 2) res = min(res, p.min1 + p.min2);
			}
			res == int(2e9) ? cout << "-1\n" : cout << res << "\n";
		}
	}
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