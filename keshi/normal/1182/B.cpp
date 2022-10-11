#include <bits/stdc++.h>
using namespace std;
int h, w, x, y, minw, maxw, minh, maxh;
bool a[510][510];
char s;
int main(){
	cin >> h >> w;
	x = -1;
	y = -1;
	minw = w + 1;
	maxw = -1;
	minh = h + 1;
	maxh = -1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> s;
			if(s == '*'){
				a[j][i] = 1;
				minw = min(minw, j);
				maxw = max(maxw, j);
				minh = min(minh, i);
				maxh = max(maxh, i);
				if(x == -1){
					x = j;
				}
				if(x != j){
					if(y == -1){
						y = i;
					}
					if(y != i){
						cout << "NO";
						return 0;
					}
				}
			}
		}
	}
	if(x == minw || x == maxw || y == minh || y == maxh){
		cout << "NO";
	}
	else{
		for(int i = minw; i <= maxw; i++){
			if(!a[i][y]){
				cout << "NO";
				return 0;
			}
		}
		for(int i = minh; i <= maxh; i++){
			if(!a[x][i]){
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
	}
	return 0;
}