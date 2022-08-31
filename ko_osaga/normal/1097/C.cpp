#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 500005;
char buf[MAXN];

vector<int> v, w;
int c0;

int main(){
	int n; scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s", buf);
		int cur = 0, minv = 0;
		for(int j=0; buf[j]; j++){
			if(buf[j] == '(') cur++;
			else cur--;
			minv = min(minv, cur);
		}
		if(cur < 0){
			if(minv < cur) continue;
			w.push_back(cur);
		}
		if(cur >= 0){
			if(minv < 0) continue;
			if(cur) v.push_back(cur);
			else c0++;
		}
	}
	int ret = c0 / 2;
	sort(v.begin(), v.end());
	multiset<int> ms;
	for(auto &i : w) ms.insert(-i);
	for(auto &i : v){
		if(ms.find(i) != ms.end()){
			ms.erase(ms.find(i));
			ret++;
		}
	}
	cout << ret << endl;
}