#include <bits/stdc++.h>

using namespace std;


vector<int> pos[155];
int n, a[155];
char ans[155];


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	pos[a[i]].push_back(i);
    }
    int cnt1 = 0, cntBig = 0;
    for(int i = 0; i < 155; i++) {
    	if(pos[i].size() == 1) {
    		cnt1++;
    	}
    	else if(pos[i].size() > 2) {
    		cntBig++;
    	}
    }
	for(int i = 0, kek = 0; i < 155; i++) {
		if(pos[i].size() == 1) {
			ans[pos[i][0]] = char('A' + kek);
			kek ^= 1;
		}
		else {
			for(auto j : pos[i]) {
				ans[j] = 'A';
			}
		}
	}

	if(cnt1 % 2 == 1) {
		if(cntBig == 0) {
			return cout << "NO", 0;
		}
		for(int i = 0; i < 155; i++) {
			if(pos[i].size() > 2) {
				ans[pos[i][0]] = 'B';
				break;
			}
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; i++) {
		cout << ans[i];
	}

}