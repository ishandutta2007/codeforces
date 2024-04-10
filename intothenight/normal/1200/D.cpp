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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vs a(n);
	cin >> a;
	vector<vi> cnt(n + 1, vi(n + 1));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (a[i - 1][j - 1] == 'B');
		}
	}
	auto num = [&](int lx, int ly, int ux, int uy){
		return cnt[ux][uy] + cnt[lx][ly] - cnt[lx][uy] - cnt[ux][ly];
	};
	vi scol(n + 1), srow(n + 1);
	for(int i = 1; i <= n; i ++){
		scol[i] = scol[i - 1] + !num(i - 1, 0, i, n);
		srow[i] = srow[i - 1] + !num(0, i - 1, n, i);
	}
	vector<vi> col(n - k + 1, vi(n - k + 1)), row(n - k + 1, vi(n - k + 1));
	for(int i = 0; i + k <= n; i ++){ // row i ~ i + k
		deque<bool> q;
		int cur_sum = 0;
		for(int j = 0; j < k - 1; j ++){
			bool ok = (num(0, j, n, j + 1) == num(i, j, i + k, j + 1));
			cur_sum += ok;
			q.push_back(ok);
		}
		for(int j = 0; j + k <= n; j ++){
			bool ok = (num(0, j + k - 1, n, j + k) == num(i, j + k - 1, i + k, j + k));
			cur_sum += ok;
			q.push_back(ok);
			col[i][j] = cur_sum;
			cur_sum -= q.front();
			q.pop_front();
		}
	}
	for(int j = 0; j + k <= n; j ++){ // col j ~ j + k
		deque<bool> q;
		int cur_sum = 0;
		for(int i = 0; i < k - 1; i ++){
			bool ok = (num(i, 0, i + 1, n) == num(i, j, i + 1, j + k));
			cur_sum += ok;
			q.push_back(ok);
		}
		for(int i = 0; i + k <= n; i ++){
			bool ok = (num(i + k - 1, 0, i + k, n) == num(i + k - 1, j, i + k, j + k));
			cur_sum += ok;
			q.push_back(ok);
			row[i][j] = cur_sum;
			cur_sum -= q.front();
			q.pop_front();
		}
	}
	int res = 0;
	for(int i = 0; i <= n - k; i ++){
		for(int j = 0; j <= n - k; j ++){
			res = max(res, col[i][j] + scol[i] + scol[n] - scol[i + k] + row[i][j] + srow[j] + srow[n] - srow[j + k]);
		}
	}
	cout << res;
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