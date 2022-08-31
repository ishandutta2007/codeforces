#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int mex(set<int> & st){
	for(int val : st)
	for(int i = 0; 1; i++) if(!st.count(i)) return i;
}
map<int, int> dp;
inline int get(int mask){
	if(!mask) return 0;
	if(dp.find(mask) != dp.end()) return dp[mask];
	vector<int> vec;
	for(int i = 30; i >= 1; i--){
		if(mask & ( 1 << i)) vec.push_back(i);
	}
	set<int> st;
	for(int i = 30; i >= 1; i--){
		int newmask = 0;
		if(vec[0] >= i){
			int j = 0;
			for(; j < vec.size() && vec[j] >= i; j++){
				if(vec[j] != i) newmask |= (1 << (vec[j] - i));
			}
			for(; j < vec.size(); j++) newmask |= (1 << vec[j]);
			st.insert(get(newmask));
		}
	}
	int ret = mex(st);
	return dp[mask] = ret;
}

map<int, int> fact;
void factorize(int n){
	for(int p = 2; p * p <= n; p++){
		if(n % p == 0){
			int k = 0;
			while(n % p == 0){
				n /= p;
				k++;
			}
			fact[p] |= (1 << k);
		}
	}
	if(n != 1) fact[n] |= 2;
}
int main(){
	int n, x;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		factorize(x);
	}
	int g = 0;
	for(auto it : fact){
		g ^= get(it.second);
	}
	cout << ((g == 0) ? "Arpa" : "Mojtaba");
}