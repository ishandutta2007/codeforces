#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 2100005;

char buf[MAXN];
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = -(n-1); i <= (n-1); i++){
		if(i == 0) continue;
		cout << "?";
		for(int j = 0; j < n-1; j++) cout << " " << 1 + max(-i, 0);
		cout << " " <<  1 + max(i, 0) << endl;
		int y; cin >> y;
		if(y > 0) a[y - 1] = i;
	}
	int minv = *min_element(all(a));
	printf("!");
	for(auto &i : a) i -= minv, printf(" %d", i+1);
	cout << endl;
}