#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << arr.first << " " << arr.second << "\n";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
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
template<class T>
using Ftn = function<T(T, T)>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct T{
	string s;
	bitset<8> val;
	int flag = false; // flag: contains |
	bool operator<(const T &otr) const{
		return s.size() == otr.s.size() ? s > otr.s : s.size() > otr.s.size();
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<T> q;
	q.push({"x", bitset<8>("00001111")});
	q.push({"y", bitset<8>("00110011")});
	q.push({"z", bitset<8>("01010101")});
	q.push({"!x", bitset<8>("11110000")});
	q.push({"!y", bitset<8>("11001100")});
	q.push({"!z", bitset<8>("10101010")});
	vector<vector<T>> p(2, vector<T>(1 << 8));
	p[0][bitset<8>("00001111").to_ulong()] = {"x", bitset<8>("00001111")};
	p[0][bitset<8>("00110011").to_ulong()] = {"y", bitset<8>("00110011")};
	p[0][bitset<8>("01010101").to_ulong()] = {"z", bitset<8>("01010101")};
	p[0][bitset<8>("11110000").to_ulong()] = {"!x", bitset<8>("11110000")};
	p[0][bitset<8>("11001100").to_ulong()] = {"!y", bitset<8>("11001100")};
	p[0][bitset<8>("10101010").to_ulong()] = {"!z", bitset<8>("10101010")};
	vector<T> L;
	vector<vi> visited(2, vi(1 << 8));
	vector<vs> res(2, vs(1 << 8, string(100, '?')));
	while(!q.empty()){
		auto [s, val, flag] = q.top();
		q.pop();
		if(!visited[flag][val.to_ulong()]){
			visited[flag][val.to_ulong()] = true;
			for(auto [S, Val, Flag]: L){
				string R;
				bitset<8> Rval;
				int Rflag;
				R = min(S + "|" + s, s + "|" + S);
				Rval = Val | val;
				Rflag = true;
				int e = Rval.to_ulong();
				if(!visited[Rflag][e] && (p[Rflag][e].s.empty() || p[Rflag][e] < T{R, Rval, Rflag})){
					q.push({R, Rval, Rflag});
					p[Rflag][e] = {R, Rval, Rflag};
				}

				R = "!(" + R + ")";
				Rval = ~Rval;
				Rflag = false;
				e = Rval.to_ulong();
				if(!visited[Rflag][e] && (p[Rflag][e].s.empty() || p[Rflag][e] < T{R, Rval, Rflag})){
					q.push({R, Rval, Rflag});
					p[Rflag][e] = {R, Rval, Rflag};
				}

				auto A = Flag ? "(" + S + ")" : S, B = flag ? "(" + s + ")" : s;
				R = min(A + "&" + B, B + "&" + A);
				Rval = Val & val;
				Rflag = false;
				e = Rval.to_ulong();
				if(!visited[Rflag][e] && (p[Rflag][e].s.empty() || p[Rflag][e] < T{R, Rval, Rflag})){
					q.push({R, Rval, Rflag});
					p[Rflag][e] = {R, Rval, Rflag};
				}

				R = "!(" + R + ")";
				Rval = ~Rval;
				Rflag = false;
				e = Rval.to_ulong();
				if(!visited[Rflag][e] && (p[Rflag][e].s.empty() || p[Rflag][e] < T{R, Rval, Rflag})){
					q.push({R, Rval, Rflag});
					p[Rflag][e] = {R, Rval, Rflag};
				}
			}
			L.push_back({s, val, flag});
			res[flag][val.to_ulong()] = s;
		}
	}
	int n;
	cin >> n;
	while(n --){
		bitset<8> s;
		cin >> s;
		auto A = res[0][s.to_ullong()], B = res[1][s.to_ullong()];
		if(A.size() != B.size()) cout << (A.size() < B.size() ? A : B) << "\n";
		else cout << (A < B ? A : B) << "\n";
	}
	return 0;
}
/*
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