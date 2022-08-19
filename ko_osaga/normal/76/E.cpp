#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<int> vx, vy;

lint solve(vector<int> &v){
	sort(v.begin(), v.end());
	lint sqs = 0, ls = 0;
	for(auto &i : v){
		sqs += 1ll * i * i;
		ls += i;
	}
	return sqs * v.size() - ls * ls;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x, y;
		scanf("%d %d",&x,&y);
		vx.push_back(x);
		vy.push_back(y);
	}
	cout << solve(vx) + solve(vy);
}