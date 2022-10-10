#include<bits/stdc++.h>
#include<chrono>
#include<random>
using namespace std;
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
struct fastseg{
	int n;
	vector<T> arr;
	BO bin_op;
	T id;
	fastseg(const vector<T> &_arr, BO _bin_op, const T &_id): n(_arr.size()), bin_op(_bin_op), id(_id), arr(n << 1, _id){
		for(int i = 0; i < n; i ++) arr[i + n] = _arr[i];
		build();
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
	int n, k;
	string s;
	cin >> n >> k >> s;
	vi left(n, -1);
	deque<int> q;
	for(int i = 0; i < n; i ++){
		while(!q.empty() && i - q.front() > k) q.pop_front();
		if(s[i] == '1') q.push_back(i);
		if(!q.empty()) left[i] = q.front();
	}
	vl d(n);
	d[0] = 1;
	fastseg tr(d, [&](ll x, ll y){return min(x, y);}, ll(9e18));
	for(int i = 1; i < n; i ++){
		if(left[i] != -1){
			if(left[i] > k){
				d[i] = tr.query(left[i] - k - 1, left[i]) + left[i] + 1;
			}
			else{
				d[i] = left[i] + 1;
			}
		}
		else{
			d[i] = d[i - 1] + i + 1;
		}
		tr.update(i, d[i]);
	}
	cout << d[n - 1];
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