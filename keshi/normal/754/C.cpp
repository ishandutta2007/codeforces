//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 300;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

int t, n, m;
string s[maxn], msg[maxn];
map<string, int> mp;
bool dp[maxn][maxn];

vector<int> get(string s){
	vector<int> vec;
	string ss;
	s += ' ';
	for(char c : s){
		if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')){
			ss += c;
		}
		else{
			if(mp.find(ss) != mp.end()){
				vec.pb(mp[ss]);
			}
			ss = "";
		}
	}
	return vec;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		mp.clear();
		for(int i = 1; i <= n; i++){
			cin >> s[i];
			mp[s[i]] = i;
		}
		cin >> m;
		getline(cin, msg[0]);
		bool ride = 0;
		int p = -1;
		for(int i = 1; i <= m; i++){
			getline(cin, msg[i]);
			string usr, txt;
			bool ff = 0;
			for(char c : msg[i]){
				if(c == ':'){
					ff = 1;
					continue;
				}
				if(ff) txt += c;
				else usr += c;
			}
			msg[i] = txt;
			vector<int> names = get(txt);
			if(usr != "?"){
				for(int j = 1; j <= n; j++){
					dp[i][j] = 0;
				}
				if(p == mp[usr]){
					ride = 1;
				}
				dp[i][mp[usr]] = 1;
				p = mp[usr];
				continue;
			}
			for(int j = 1; j <= n; j++){
				dp[i][j] = 1;
			}
			for(int j : names){
				dp[i][j] = 0;
			}
			if(p != -1){
				dp[i][p] = 0;
			}
			p = -2;
			for(int j = 1; j <= n; j++){
				if(!dp[i][j]) continue;
				if(p == -2) p = j;
				else p = -1;
			}
			if(p == -2){
				ride = 1;
				p = -1;
			}
		}
		if(ride){
			cout << "Impossible\n";
			continue;
		}
		p = -1;
		for(int i = m; i > 0; i--){
			for(int j = 1; j <= n; j++){
				if(p != j && dp[i][j]){
					p = j;
					break;
				}
			}
			msg[i] = s[p] + ':' + msg[i];
		}
		for(int i = 1; i <= m; i++){
			cout << msg[i] << "\n";
		}
	}
	
	return 0;
}