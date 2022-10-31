// Hydro submission #621ca93d691e5f399cb2bd76@1646045501472
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

const int MAXN = 200100;
typedef long long ll;

int vis[310][310];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void slove() {
	string s; cin >> s;
	int x = 150, y = 150;
	vis[x][y] = 1;
	for(auto c : s){
		if(c == 'L') y--;
		if(c == 'R') y++;
		if(c == 'U') x--;
		if(c == 'D') x++;
		if(vis[x][y] == 1) {
			cout << "BUG" << '\n';
			return;
		}
		vis[x][y] = 1;
		int cnt = 0;
		for(int i = 0; i < 4; i++){
			if(vis[x + dx[i]][y + dy[i]] == 1) cnt++;
		}
		if(cnt > 1) {
			cout << "BUG" << '\n';
			return;
		}
	}
	cout << "OK" << '\n';


}



int main(){
	//ios_base::sync_with_stdio(0), cin.tie(0);
	slove();
	

}