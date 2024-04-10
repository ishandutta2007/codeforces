#include<bits/stdc++.h>
#include<chrono>
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

struct hero{
	int ind, pos, hp;
	hero(){}
	hero(int ind, int pos, int hp): ind(ind), pos(pos), hp(hp){};
	bool operator<(const hero &other){return pos < other.pos;}
};
ostream &operator<<(ostream &out, const hero &x){
	cout << "( index = " << x.ind << ", pos = " << x.pos << ", hp = " << x.hp << ") ";
	return out;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<hero> h(m);
	for(int i = 0; i < m; i ++){
		int x, y;
		cin >> x >> y, x --;
		h[i] = {i + 1, x, y};
	}
	sort(all(h));
	vi board(n);
	cin >> board;
	for(int rally = 0; rally < n; rally ++){
		vector<hero> left, right;
		auto p = lower_bound(all(h), hero(0, rally, 0)) - h.begin();
		for(int i = p - 1; i >= 0; i --) left.push_back(h[i]);
		for(int i = p; i < m; i ++) right.push_back(h[i]);
		if(!left.empty()){
			vi wait, res;
			int mark = rally;
			for(auto &x: left){
				int HP = x.hp;
				bool ok = true;
				for(int i = x.pos; i <= mark; i ++){
					HP += board[i];
					if(HP < 0){
						ok = false;
						break;
					}
				}
				if(ok){
					res.push_back(x.ind);
					for(auto u: wait){
						res.push_back(u);
					}
					wait.clear();
					mark = x.pos - 1;
				}
				else{
					wait.push_back(x.ind);
				}
			}
			if(wait.empty()){
				mark = rally + 1;
				for(auto &x: right){
					int HP = x.hp;
					bool ok = true;
					for(int i = x.pos; i >= mark; i --){
						HP += board[i];
						if(HP < 0){
							ok = false;
							break;
						}
					}
					if(ok){
						res.push_back(x.ind);
						for(auto u: wait){
							res.push_back(u);
						}
						wait.clear();
						mark = x.pos + 1;
					}
					else{
						wait.push_back(x.ind);
					}
				}
				if(wait.empty()){
					cout << rally + 1 << "\n" << res;
					return 0;
				}
			}
		}
		if(!right.empty()){
			vi wait, res;
			int mark = rally;
			for(auto &x: right){
				int HP = x.hp;
				bool ok = true;
				for(int i = x.pos; i >= mark; i --){
					HP += board[i];
					if(HP < 0){
						ok = false;
						break;
					}
				}
				if(ok){
					res.push_back(x.ind);
					for(auto u: wait){
						res.push_back(u);
					}
					wait.clear();
					mark = x.pos + 1;
				}
				else{
					wait.push_back(x.ind);
				}
			}
			if(wait.empty()){
				mark = rally - 1;
				for(auto &x: left){
					int HP = x.hp;
					bool ok = true;
					for(int i = x.pos; i <= mark; i ++){
						HP += board[i];
						if(HP < 0){
							ok = false;
							break;
						}
					}
					if(ok){
						res.push_back(x.ind);
						for(auto u: wait){
							res.push_back(u);
						}
						wait.clear();
						mark = x.pos - 1;
					}
					else{
						wait.push_back(x.ind);
					}
				}
				if(wait.empty()){
					cout << rally + 1 << "\n" << res;
					return 0;
				}
			}
		}
	}
	cout << -1;
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