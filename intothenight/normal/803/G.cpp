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
	int N, lg;
	vector<T> log;
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
		if(l >= r) return (int)2e9;
		int t = log[r - l];
		return bin_op((*this)[l][t], (*this)[r - (1 << t)][t]);
	}
	sparse operator=(const sparse &otr){
		N = otr.N, lg = otr.lg, log = otr.log;
		bin_op = otr.bin_op;
		this->resize(N, vector<T>(lg + 1));
		for(int i = 0; i < N; i ++){
			for(int j = 0; j <= lg; j ++){
				(*this)[i][j] = otr[i][j];
			}
		}
		return *this;
	}
};

sparse<int, function<int(int, int)>> tb;

int n, k;
int getval(int l, int r){
	if(r - l >= n){
		return tb.query(0, n);
	}
	if(l % n >= r % n){
		return min(tb.query(l % n, n), tb.query(0, r % n));
	}
	return tb.query(l % n, r % n);
}

int lop(int x, int y){return x + y;}
int qop(int x, int y){return min(x, y);}
int aop(int x, int y, int z){return min(x, y);}
int disabled = -2e9, lid = 0, qid = 2e9;
template<class T>
struct ldseg{
	ldseg *l = 0, *r = 0;
	int low, high;
	T lset = disabled, lazy = lid, val = qid;
	ldseg(int low, int high): low(low), high(high){
		val = getval(low, high);
	}
	ldseg(int low, int high, const vector<T> &arr): low(low), high(high){
		if(high - low > 1){
			int mid = low + (high - low) / 2;
			l = new ldseg(low, mid, arr);
			l->val = getval(low, mid);
			r = new ldseg(mid, high, arr);
			r->val = getval(mid, high);
			val = qop(l->val, r->val);
		}
		else val = arr[low];
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new ldseg(low, mid);
			l->val = getval(low, mid);
			r = new ldseg(mid, high);
			r->val = getval(mid, high);
		}
		if(lset != disabled){
			l->set(low, high, lset);
			r->set(low, high, lset);
			lset = disabled;
		}
		else if(lazy != lid){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			lazy = lid;
		}
	}
	void set(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lset = x;
			lazy = lid;
			val = aop(qid, x, high - low);
		}
		else{
			push();
			l->set(ql, qr, x);
			r->set(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	void update(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			if(lset != 	disabled) lset = lop(lset, x);
			else lazy = lop(lazy, x);
			val = aop(val, x, high - low);
		}
		else{
			push(), l->update(ql, qr, x), r->update(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	T query(int ql, int qr){
		if(qr <= low || high <= ql) return qid;
		if(ql <= low && high <= qr) return val;
		push();
		return qop(l->query(ql, qr), r->query(ql, qr));
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	vi b(n);
	cin >> b;
	tb = sparse<int, function<int(int, int)>>(b, [](int x, int y){return min(x, y);});
	ldseg<int> tr(0, n * k);
	int q;
	cin >> q;
	while(q --){
		int type;
		cin >> type;
		if(type == 1){
			int l, r, x;
			cin >> l >> r >> x;
			tr.set(l - 1, r, x);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << tr.query(l - 1, r) << "\n";
		}
	}
	return 0;
}
/*


*/
 
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\                                    //
//           +++`+``+`+`++++        ///`````````````````````````````\\                              //
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