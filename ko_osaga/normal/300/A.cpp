#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

vector<int> a[3];

int main(){
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x < 0) a[0].push_back(x);
		else if(x > 0) a[1].push_back(x);
		else a[2].push_back(x);
	}
	if(a[1].size() == 0){
		for(int j=0; j<2; j++){
			a[1].push_back(a[0].back());
			a[0].pop_back();
		}
	}
	if(a[0].size() % 2 == 0){
		a[2].push_back(a[0].back());
		a[0].pop_back();
	}
	for(int i=0; i<3; i++){
		printf("%d ", a[i].size());
		for(auto &j : a[i]) printf("%d ",j);
		puts("");
	}
}