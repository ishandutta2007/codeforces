#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 26;
vector<int> con[N];

string name[105];
int deg[N];
bool chk(string a, string b){
	int sa = a.length(), sb = b.length();
	for(int i = 0; i < sa && i < sb; i++){
		if(a[i] != b[i]){
			con[a[i] - 'a'].push_back(b[i] - 'a');
			deg[b[i] - 'a']++;
			return 1;
		}
	}
	if(sa > sb) return 0;
	return 1;
}

set<pair<int, int> > st;
char order[N];
bool done[N];
int main(){
	int n;
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> name[i];
	}

	for(int i = 0; i < n - 1; i++){
		if(!chk(name[i], name[i + 1])){
			cout << "Impossible";
			return 0;
		}
	}

	for(int i = 0; i < 26; i++)
		st.insert({deg[i], i});

	int cnt = 0;
	while(!st.empty()){
		auto it = *st.begin();
		int d = it.F;
		order[cnt++] = 'a' + it.S;
		if(d != 0){
			cout << "Impossible";
			return 0;
		}
		st.erase(st.begin());
		done[it.S] = 1;
		for(int v : con[it.S]){
			if(!done[v]){
				st.erase({deg[v], v});
				deg[v]--;
				st.insert({deg[v], v});
			}
		}
	}
	cout << order;
}