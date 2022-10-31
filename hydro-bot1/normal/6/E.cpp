// Hydro submission #6220a6cf3d794d828a9cb8bd@1646307023860
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
const int logn = 21;
const int maxn = 100100;
int n, k;
int a[maxn];
int f[maxn][logn + 1], ff[maxn][logn + 1];
int Logn[maxn + 1];

void init(int n){
	Logn[1] = 0;
	Logn[2] = 1; 
	for(int i = 2; i <= n; i++){
		Logn[i] = Logn[i/2] + 1;
	}
}
void ST_prework(){
	for(int i = 1; i <= n; i++) {
		f[i][0] = a[i];
		ff[i][0] = a[i];
	}
	int t = Logn[n] + 1;
	for(int j = 1; j < t; j++)
		for(int i = 1; i <= n - (1 << j) + 1; i++){
			f[i][j] = max(f[i][j-1], f[i+(1 << (j - 1))][j-1]);
			ff[i][j] = min(ff[i][j-1], ff[i + (1 << (j - 1))][j-1]);
		}
}

int ST_maxquery(int l, int r){
	int k = Logn[r - l + 1];
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int ST_minquery(int l, int r){
	int k = Logn[r - l + 1];
	return min(ff[l][k], ff[r - (1 << k) + 1][k]);
}

vector<pair<int, int>> arr;

void slove(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	multiset<int> st;
	vector<int> vec;
	int tmp = 1, maxn = 0;
	for(int i = 1; i <= n; i++){
		st.insert(a[i]);
		while(*st.rbegin() - *st.begin() > k){
			st.erase(st.find(a[tmp]));
			tmp++;
		}
		if((int)st.size() > maxn){
			maxn = st.size();
			arr.clear();
			arr.push_back({tmp, i});
		} else {
			arr.push_back({tmp, i});
		}
	}
	cout << maxn  << " " << arr.size() << '\n';
	for(auto c : arr){
		cout << c.first << ' ' << c.second << '\n';
	}

}

void slove2(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	init(n);
	ST_prework();
	vector<pair<int, int>> vec;
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		int l = i, r = n; 
		while(l < r){
			// cout << l << ' ' << r << '\n';
			int mid = (l + r + 1) >> 1;
			if(ST_maxquery(i, mid) - ST_minquery(i, mid) > k){
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		if(l - i + 1 == maxn){
			vec.push_back({i, l});
		} else if(l - i + 1 > maxn){
			maxn = l - i + 1;
			vec.clear();
			vec.push_back({i, l});
		}
	}
	cout << maxn << " " << vec.size() << '\n';
	for(auto c : vec){
		cout << c.first << ' ' << c.second << '\n'; 
	}

}


int main(){
	slove2();


}