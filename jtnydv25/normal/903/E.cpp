#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define F first
#define S second
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
const int N = 5005;
string s[N];

set<int> pos[N];
set<int> st;
vector<int> vec;
vector<int> V[N];
inline char get(int ind, int I, int i, int j){
	if(ind == i) return s[I][j];
	if(ind == j) return s[I][i];
	return s[I][ind];
}
set<char> st0;

int main(){
	int n, k;
	cin >> k >> n;
	for(int i = 1; i <= k; i++) cin >> s[i];
	for(int i = 0; i < n; i++) st0.insert(s[1][i]);
	bool ok = 1;
	for(int i = 2; i <= k; i++){
		set<char> st2;
		for(int j = 0; j < n; j++){
			if(s[i][j] != s[1][j]) pos[i].insert(j), V[i].push_back(j);
			st2.insert(s[i][j]);
		}
		if(pos[i].size() > 4){
			cout << -1;
			return 0;
		}
		if(st2 != st0){
			cout << -1;
			return 0;
		}
	}
	bool allDiff = 1;
	if(st0.size() != n) allDiff = 0;
	ok = 1;
	if(!allDiff){
		for(int ind = 2; ind <= k; ind++){
			if(pos[ind].size() > 2 || pos[ind].size() == 1){
				ok = 0; break;
			}
			if(pos[ind].size() == 2){
				int ind1 = V[ind][0], ind2 = V[ind][1];
				if(!(s[ind][ind1] == s[1][ind2] && s[ind][ind2] == s[1][ind1])){
					ok = 0;
					break;
				}
			}
		}
		if(ok){
			cout << s[1];
			return 0;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ok = 1;
			for(int ind = 2; ind <= k; ind++){
				st = pos[ind];
				st.insert(i);
				st.insert(j);
				vec.clear();
				for(int x : st){
					if(get(x, 1, i, j) != s[ind][x])
						vec.push_back(x);
				}
				if(vec.size() > 2 || vec.size() == 1) ok = 0;
				if(allDiff && vec.empty()) ok = 0;
				if(vec.size() == 2){
					if(!(s[ind][vec[1]] == get(vec[0], 1, i, j) 
						&& s[ind][vec[0]] == get(vec[1], 1, i, j)))
						ok = 0;
				}
				if(!ok) break;
			}
			if(ok){
				char temp = s[1][j];
				s[1][j] = s[1][i];
				s[1][i] = temp;
				cout << s[1] << endl;
				return 0;
			}
		}
	}
	cout << -1;
}