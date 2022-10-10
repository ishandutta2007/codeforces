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

ll lop(ll x, ll y){return x + y;}
ll qop(ll x, ll y){return x + y;}
ll aop(ll x, ll y, ll z){return x + y * z;}
ll disabled = -9e18;
ll lid = 0;
ll qid = 0;
template<class T = long long>
struct ldseg{
	ldseg *l = 0, *r = 0;
	int low, high;
	T lset = disabled, lazy = lid, val = qid;
	ldseg(int low, int high): low(low), high(high){}
	ldseg(const vector<T> &arr, int low, int high): low(low), high(high){
		if(high - low > 1){
			int mid = low + (high - low) / 2;
			l = new ldseg(arr, low, mid);
			r = new ldseg(arr, mid, high);
			val = qop(l->val, r->val);
		}
		else val = arr[low];
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new ldseg(low, mid);
			r = new ldseg(mid, high);
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
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	ldseg tr(vl(n + 3), 0, n + 3);
	int sz = 1;
	for(int i = 0; i < n; i ++){
		int type;
		cin >> type;
		if(type == 1){
			int a, x;
			cin >> a >> x;
			tr.update(0, a, x);
			cout << 1.0 * tr.query(0, sz) / sz << "\n";
		}
		else if(type == 2){
			int k;
			cin >> k;
			tr.set(sz, sz + 1, k);
			sz ++;
			cout << 1.0 * tr.query(0, sz) / sz << "\n";
		}
		else{
			sz --;
			cout << 1.0 * tr.query(0, sz) / sz << "\n";
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