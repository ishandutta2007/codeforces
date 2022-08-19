#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int b, g, n;
	cin >> b >> g >> n;
	int ret = 0;
	for(int i=0; i<=b; i++){
		int ng = n - i;
		if(ng < 0 || ng > g) continue;
		ret++;
	}
	cout << ret << endl;
}