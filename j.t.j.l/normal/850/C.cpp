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

void read(){

}

int a[111];
int vis[MAXN];

unordered_map<int, int> mp;

int sg(int msk){
	auto maki = mp.find(msk);
	if (maki != mp.end()){
		return maki->second;
	}
	vector<int> a;
	for (int i = 1; (1ll << (i - 1)) <= msk; i++){
		int nxt = (msk >> i) | (msk & ((1 << (i - 1)) - 1));
		a.push_back(sg(nxt));
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	
	//cout << "====================  " << msk << ":  ";
	//for (auto &x : a) cout << x << ' '; cout << endl;
	
	for (int i = 0, j = 0; i < a.size(); i++, j++){
		if (a[i] != j)
			return mp[msk] = j;
	}
	return mp[msk] = a.size();
}

int gao(int p){
	vector<int> f;
	for (int i = 1; i <= n; i++){
		if (a[i] % p == 0){
			int cnt = 0;
			while(a[i] % p == 0){
				cnt++;
				a[i] /= p;
			}
			f.push_back(cnt);
		}
	}
	if (f.size() == 0)
		return 0;
	sort(f.begin(), f.end());
	f.erase(unique(f.begin(), f.end()), f.end());
	int msk = 0;
	/*
	cout << p << endl;
	for (auto &x : f)
		cout << x << ' '; cout << endl << endl;
	*/
	for (auto &x : f)
		msk |= (1 << (x - 1));
	
	//cout << "QAQ: " << msk << ' ' << sg(msk) << endl;
	
	return sg(msk);
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	mp[0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 0;
	int N = 1e5;
	for (int i = 2; i <= N; ){
		ans ^= gao(i);
		for (int j = i; j <= N; j += i){
			vis[j] = 1;
		}
		while(i <= N && vis[i] == 1)
			i++;
	}
	for (int i = 1; i <= n; i++)
		if (a[i] != 1){
			ans ^= gao(a[i]);
		}
	puts(ans ? "Mojtaba" : "Arpa");
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
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