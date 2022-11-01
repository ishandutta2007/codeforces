#include <iostream>

#define T(B) ((B)?0:1)

using namespace std;
bool xBanned[1000];
bool yBanned[1000];
int main(){
	int n, m;
	cin >> n >> m;
	xBanned[0] = xBanned[n - 1] = yBanned[0] = yBanned[n - 1] = true;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		xBanned[x - 1] = true;
		yBanned[y - 1] = true;
	}
	int score = 0;
	for(int i = 0; i < n / 2; i++){
		int sc = T(xBanned[i]) + T(xBanned[n - 1 - i]) + T(yBanned[i]) + T(yBanned[n - 1 - i]);
		score += sc;
	}
	if(n % 2 == 1){
		int i = n / 2;
		if(!xBanned[i] || !yBanned[i])
			score++;
	}
	cout << score << endl;
	return 0;
}