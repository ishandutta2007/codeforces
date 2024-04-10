#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, sx, sy;
	cin>>n>>m>>sx>>sy;
	cout<<sx<< ' '<<sy<<'\n';
	for(int i = 1; i <= m; ++i) {
		if(i != sy)
			cout<<sx<<' '<<i<<'\n';
	}
	int up = sx - 1;
	for(int i = sx - 1, cnt = 1; i >= 1; --i, ++cnt) {
		if(cnt & 1) {
			for(int j = m; j >= 1; --j) {
				cout<<i<<' '<<j<<'\n';
			}
		}
		else {
			for(int j = 1; j <= m; ++j) {
				cout<<i<<' '<<j<<'\n';
			}
		}
	}
	if(up & 1) {
		for(int i = sx + 1, cnt = 1; i <= n; ++i, ++cnt) {
			if(cnt & 1) {
				for(int j = 1; j <= m; ++j) {
					cout<<i<<' '<<j<<'\n';
				}
			}
			else {
				for(int j = m; j >= 1; --j) {
					cout<<i<<' '<<j<<'\n';
				}
			}
		}
	}
	else {
		for(int i = sx + 1, cnt = 1; i <= n; ++i, ++cnt) {
			if(cnt & 1) {
				for(int j = m; j >= 1; --j) {
					cout<<i<<' '<<j<<'\n';
				}
			}
			else {
				for(int j = 1; j <= m; ++j) {
					cout<<i<<' '<<j<<'\n';
				}
			}
		}
	}
    return 0;
}