#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iomanip>
#include <bitset>

using namespace std;

const int MX = 61;
vector< vector< bitset<501> > > gA(MX);
vector< vector<  bitset<501> > > gB(MX);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i =0; i < MX; i++){
		gA[i].resize(n);
		gB[i].resize(n);
	}
	for(int i =0; i < m; i++){
		int a, b;
		cin >> a >> b; a--;b--;
		int c;
		cin >> c;
		if(c){
			gB[0][a][b] = 1;
		}
		else{
			gA[0][a][b] = 1;
		}
	}
	for(int lvl = 1; lvl < MX; lvl++){
		for(int i =0; i <n; i++){
			for(int j =0; j < n; j++){ 
				if(gA[lvl - 1][i][j])
					gA[lvl][i] |= gB[lvl - 1][j];
				if(gB[lvl - 1][i][j])
					gB[lvl][i] |= gA[lvl - 1][j];
			}
		}
	}
	vector<int> now;
	now.push_back(0);
	long long len = 0;
	int cnt =0;
	for(int lvl = MX - 1; lvl >= 0; lvl--){
		vector<int> will;
		vector<bool>used(n);
		for(int i =0; i < now.size(); i++){
			int fr = now[i];
			for(int j =0; j < n; j++){
				if(cnt){
					if(gB[lvl][fr][j] && !used[j]){
						will.push_back(j);
						used[j] = 1;
					}
				}
				else{
					if(gA[lvl][fr][j] && !used[j]){
						will.push_back(j);
						used[j] = 1;
					}
				}
			}
		}
		if(will.size()){
			now = will;
			len += 1ll << lvl;
			cnt ^= 1;
		}
	}
	if(len > 1e18)
		cout << -1;
	else
		cout << len;
	return 0;
}