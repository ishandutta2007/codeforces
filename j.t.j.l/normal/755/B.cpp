#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

int cnt = 0;

int f[MAXN];
map<string, int> mp;
string s[MAXN], t[MAXN];

void read(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		mp[s[i]] = 1;
	}
	for(int i = 1; i <= m; i++){
		cin>>t[i];
		if (mp.find(t[i]) == mp.end()){
			mp[t[i]] = 1;
		}
		else{
			mp[t[i]] = 2;
		}
	}
	//for(auto x : mp)
	//	cout<<x.first<<' '<<x.second<<endl;
	//cnt = mp.size();
}

void solve(int casi){
	/*
	for(int i = 1; i <= n; i++){
		f[mp[s[i]]]++;
	}
	for(int i = 1; i <= m; i++){
		f[mp[t[i]]]++;
	}*/
	int o = 0;
	for(auto x : mp)
		o += (x.second == 2);
	/*
	for(int i = 1; i <= cnt; i++){
		cout<<f[i]<<' ';
		o += (f[i] == 2);
	}
	cout<<endl;*/
	int oop = n + m + 1;
	n -= o, m -= o;
	//cout<<n<<' '<<m<<' '<<o<<endl;
	for(int i = 1; ; i++){
		if (i & 1){
			if (o > 0) o--;
			else{
				if (n > 0) n--;
				else{
					puts("NO");
					return;
				}
			}
		}
		else{
			if (o > 0) o--;
			else{
				if (m > 0) m--;
				else{
					puts("YES");
					return;
				}
			}
		}
	}
}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}