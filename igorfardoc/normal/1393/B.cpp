#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vi am(100001, 0);
    for(int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	am[a]++;
    }
    int am8 = 0;
    int am6 = 0;
    int am4 = 0;
    int am2 = 0;
    for(int i = 1; i <= 100000; i++) {
    	if(am[i] >= 8) {
    		++am8;
    	} else if(am[i] >= 6) {
    		++am6;
    	} else if(am[i] >= 4) {
    		++am4;
    	} else if(am[i] >= 2) {
    		++am2;
    	}
    }
    int q;
    cin >> q;
    for(int o = 0; o < q; o++) {
    	char c;
    	int i;
    	cin >> c >> i;
    	if(am[i] >= 8) {
    		--am8;
    	} else if(am[i] >= 6) {
    		--am6;
    	} else if(am[i] >= 4) {
    		--am4;
    	} else if(am[i] >= 2) {
    		--am2;
    	}
    	if(c == '+') {
    		++am[i];
    	} else {
    		--am[i];
    	}
    	if(am[i] >= 8) {
    		++am8;
    	} else if(am[i] >= 6) {
    		++am6;
    	} else if(am[i] >= 4) {
    		++am4;
    	} else if(am[i] >= 2) {
    		++am2;
    	}
    	if(am8 >= 1 || am6 >= 2 || (am6 == 1 && (am2 >= 1 || am4 >= 1)) || am4 >= 2 || (am4 == 1 && am2 >= 2)) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}