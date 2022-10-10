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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
mt19937 rnd(time(0));

template<class T, class BO>
struct sparse: vector<vector<T>>{
	const int N, lg;
	vector<T> log;
	BO bin_op;
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
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	auto ok = [](int x, int y){
		return (x + 1) / 2 <= y;
	};
	int n;
	cin >> n;
	vi a(n);
	cin >> a;
	if(ok(*max_element(all(a)), *min_element(all(a)))){
		vi t(n, -1);
		cout << t;
		return 0;
	}
	a.resize(3 * n);
	for(int i = n; i < 3 * n; i ++){
		a[i] = a[i - n];
	}
	sparse tb(a, [](int x, int y){return max(x, y);});
	vi to(3 * n);
	for(int i = 3 * n - 1; i > 0; i --){
		if(tb.query(0, i) <= 2 * a[i]){
			continue;
		}
		int l = 0, r = i;
		while(r - l > 1){
			int m = r + l >> 1;
			if(tb.query(m, i) <= 2 * a[i]){
				r = m;
			}
			else{
				l = m;
			}
		}
		to[l] = i;
	}
	vi res(3 * n, 1);
	int t = 2e9;
	for(int i = 3 * n - 2; i >= 0; i --){
		if(a[i] <= a[i + 1]){
			res[i] = res[i + 1] + 1;
		}
		else{
			if(to[i]){
				t = min(t, to[i]);
			}
			res[i] = t - i;
		}
	}
	res.resize(n);
	cout << res;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                //
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