#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
map<vector<int>, int> mp;
queue<vector<int> > q;

int main(){
	scanf("%d", &n);
	vector<int> a(n * 2);
	for(int i = 1;i <= n * 2;i++) scanf("%d", &a[i - 1]);
	q.push(a), mp[a] = 0;
	while(!q.empty()){
		vector<int> a = q.front();q.pop();
		int val = mp[a];
		bool tag = false;
		for(int i = 0;i + 1 < a.size() && !tag;i++) if(a[i] > a[i + 1]) tag = true;
		if(!tag) return printf("%d", val), 0;
		for(int i = 0;i < a.size();i += 2) swap(a[i], a[i + 1]);
		if(mp.find(a) == mp.end()) mp[a] = val + 1, q.push(a);
		for(int i = 0;i < a.size();i += 2) swap(a[i], a[i + 1]);
		for(int i = 0;i + n < a.size();i++) swap(a[i], a[i + n]);
		if(mp.find(a) == mp.end()) mp[a] = val + 1, q.push(a);
	}
	printf("-1");
}