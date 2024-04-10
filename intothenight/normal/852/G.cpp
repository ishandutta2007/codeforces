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

template<int C>
struct aho_corasic{
	struct node{
		int par, link = -1, elink = -1;
		char cpar;
		vector<int> next, go;
		bool isleaf = false;
		int cnt = 0;
		node(int par = -1, char pch = '$'):
			par(par), cpar(pch), next(C, -1), go(C, -1){}
	};
	vector<node> arr;
	function<int(char)> trans;
	aho_corasic(function<int(char)> _trans = [](char c){return c < 'Z' ? c - 'A' : c - 'a';}):
		arr(1), trans(_trans){}
	void insert(int ind, const string &s){
		int u = 0;
		for(auto &ch: s){
			int c = trans(ch);
			if(arr[u].next[c] == -1){
				arr[u].next[c] = arr.size();
				arr.emplace_back(u, ch);
			}
			u = arr[u].next[c];
		}
		arr[u].isleaf = true;
		arr[u].cnt ++;
	}
	int get_link(int u){
		if(arr[u].link == -1){
			if(!u || !arr[u].par){
				arr[u].link = 0;
			}
			else{
				arr[u].link = go(get_link(arr[u].par), arr[u].cpar);
			}
		}
		return arr[u].link;
	}
	int get_elink(int u){
		if(arr[u].elink == -1){
			if(!u || !get_link(u)){
				arr[u].elink = 0;
			}
			else if(arr[get_link(u)].isleaf){
				arr[u].elink = get_link(u);
			}
			else{
				arr[u].elink = get_elink(get_link(u));
			}
		}
		return arr[u].elink;
	}
	int go(int u, char ch){
		int c = trans(ch);
		if(arr[u].go[c] == -1){
			if(arr[u].next[c] != -1){
				arr[u].go[c] = arr[u].next[c];
			}
			else{
				arr[u].go[c] = u == 0 ? 0 : go(get_link(u), ch);
			}
		}
		return arr[u].go[c];
	}
	void print(int u, string s = ""){
		cout << "Node " << u << ": par = " << arr[u].par << ", cpar = " << arr[u].cpar << ", string: " << s << "\n";
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
	int n, m;
	cin >> n >> m;
	aho_corasic<5> tr;
	for(int i = 0; i < n; i ++){
		string s;
		cin >> s;
		tr.insert(i, s);
	}
	auto count = [&](const string &s){
		int u = 0;
		for(auto c: s){
			if(tr.arr[u].next[c - 'a'] != -1){
				u = tr.arr[u].next[c - 'a'];
			}
			else{
				return 0;
			}
		}
		return tr.arr[u].cnt;
	};
	vs q;
	function<void(string &, int)> find = [&](string &s, int p){
		if(p == s.size()){
			q.push_back(s);
			return;
		}
		if(s[p] == '?'){
			s.erase(s.begin() + p);
			find(s, p);
			s.insert(s.begin() + p, '?');
			for(int i = 0; i < 5; i ++){
				s[p] = i + 'a';
				find(s, p + 1);
				s[p] = '?';
			}
		}
		else{
			find(s, p + 1);
		}
	};
	for(int i = 0; i < m; i ++){
		string s;
		cin >> s;
		q.clear();
		find(s, 0);
		sort(all(q));
		q.resize(unique(all(q)) - q.begin());
		int res = 0;
		for(auto &t: q){
			res += count(t);
		}
		cout << res << "\n";
	}
	return 0;
}

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