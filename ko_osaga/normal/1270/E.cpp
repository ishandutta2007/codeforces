#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
const int MAXN = 2505;
using pi = pair<int, int>;
using lint = long long;

int n;
pi a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a[i].first,&a[i].second);
		a[i].first += 1234567;
		a[i].second += 1234567;
	}
	while(true){
		vector<int> x, y;
		for(int i=0; i<n; i++){
			if(abs(a[i].first) % 2 != abs(a[i].second) % 2){
				x.push_back(i);
			}
			else{
				y.push_back(i);
			}
		}
		if(sz(x) && sz(y)){
			printf("%d\n", sz(x));
			for(auto &i : x) printf("%d ", i + 1);
			return 0;
		}
		for(int i=0; i<n; i++){
			int x = a[i].first;
			int y = a[i].second;
			if(abs(x - y) % 2) y++;
			a[i] = pi((x + y) / 2, (x - y) / 2);
		}
	}
}