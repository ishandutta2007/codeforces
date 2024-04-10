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

template<int C>
struct aho_corasic{
	struct node{
		int par, link = -1, elink = -1;
		char cpar;
		vector<int> next, go;
		int depth;
		set<int> match;
		node(int _depth = 0, int par = -1, char pch = '$'): depth(_depth), par(par), cpar(pch), next(C, -1), go(C, -1){}
	};
	vector<node> arr;
	function<int(char)> trans;
	aho_corasic(function<int(char)> _trans = [](char c){return c < 'Z' ? c - 'A' : c - 'a';}): arr(1), trans(_trans){}
	int insert(const string &s){
		int u = 0;
		for(auto &ch: s){
			int c = trans(ch);
			if(arr[u].next[c] == -1){
				arr[u].next[c] = arr.size();
				arr.emplace_back(arr[u].depth + 1, u, ch);
			}
			arr[arr[u].next[c]].par = u;
			u = arr[u].next[c];
		}
		return u;
	}
	void data_insert(int ind, const string &s){
		int u = 0;
		for(auto &ch: s){
			int c = trans(ch);
			arr[u].match.insert(ind);
			if(arr[u].next[c] == -1) break;
			u = arr[u].next[c];
		}
		arr[u].match.insert(ind);
	}
	void print(int u, string s = ""){
		cout << "Node " << u << ": depth = " << arr[u].depth << ", par = " << arr[u].par << ", string: " << s << "\n";
		for(int i = 0; i < C; i ++){
			if(arr[u].next[i] != -1){
				cout << u << " => ";
				print(arr[u].next[i], s + string(1, i + 'a'));
			}
		}
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	aho_corasic<26> tr;
	vi pos(n);
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		pos[i] = tr.insert(s);
	}
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		tr.data_insert(i, s);
	}
	int res = 0;
	vi match(n);
	priority_queue<int, vi, function<bool(int, int)>> q([&](int i, int j){
		return tr.arr[pos[i]].depth < tr.arr[pos[j]].depth;
	});
	for(int i = 0; i < n; i ++) q.push(i);
	vi used(n);
	while(!q.empty()){
		int i = q.top();
		q.pop();
		int u = pos[i];
		while(!tr.arr[u].match.empty() && used[*tr.arr[u].match.begin()]) tr.arr[u].match.erase(tr.arr[u].match.begin());
		if(!tr.arr[u].match.empty()){
			int p = *tr.arr[u].match.begin();
			match[i] = p;
			used[p] = true;
			res += tr.arr[u].depth;
			for(; u != -1; u = tr.arr[u].par){
				tr.arr[u].match.erase(p);
			}
		}
		else{
			pos[i] = tr.arr[u].par;
			q.push(i);
		}
	}
	cout << res << "\n";
	for(int i = 0; i < n; i ++) cout << i + 1 << " " << match[i] + 1 << "\n";
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