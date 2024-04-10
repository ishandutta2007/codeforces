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


 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, s, m, k;
	cin >> n >> s >> m >> k; // s: # of segs, m: # of segs to choose, k: order statistic
	vi a(n);
	cin >> a;
	vector<pii> tt(s);
	cin >> tt;
	for(auto &p: tt){
		p.first --;
	}
	sort(all(tt));
	vector<pii> t;
	for(auto p: tt){
		while(!t.empty() && t.back().first == p.first){
			t.pop_back();
		}
		if(t.empty() || t.back().second < p.second){
			t.push_back(p);
		}
	}
	s = t.size();
	m = min(s, m);
	vi temp(n, -1);
	for(int i = 0; i < s; i ++){
		temp[t[i].second - 1] = i;
	}
	vi left(n), right(n);
	for(int i = 0, p = -1; i < n; i ++){
		left[i] = p;
		if(temp[i] != -1) p = temp[i];
	}
	for(int i = n - 1, p = -1; i >= 0; i --){
		if(temp[i] != -1) p = temp[i];
		right[i] = p;
	}
	auto check = [&](int x){
		vector<vi> d(s + 1, vi(m + 1)), maxd(s + 1, vi(m + 1));
		vi cnt(n + 1);
		for(int i = 1; i <= n; i ++){
			cnt[i] = cnt[i - 1] + (a[i - 1] <= x);
		}
		for(int i = 1; i <= s; i ++){
			for(int j = 1; j <= min(i, m); j ++){
				auto [l, r] = t[i - 1];
				r = right[l];
				l = left[l];
				d[i][j] = maxd[l + 1][j - 1] + cnt[t[i - 1].second] - cnt[t[i - 1].first];
				if(r != -1) d[i][j] = max(d[i][j], maxd[r + 1][j - 1] + cnt[t[i - 1].second] - cnt[t[r].second]);
				if(d[i][j] >= k){
					return true;
				}
				maxd[i][j] = max(maxd[i - 1][j], d[i][j]);
			}
		}
		return false;
	};
	int l = 0, r = *max_element(all(a));
	if(!check(r)){
		cout << -1;
		return 0;
	}
	while(r - l > 1){
		int m = l + r >> 1;
		if(check(m)){
			r = m;
		}
		else{
			l = m;
		}
	}
	cout << r;
	return 0;
}
/*
7 6 4 5 
8 9 8 3 6 9 1 
6 6
1 3
5 7
7 7
2 5
3 3

8 9 8 3 6 9  1
(   )
    ()
        (    )
          ()
*/
 
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