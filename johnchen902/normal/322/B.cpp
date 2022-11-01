#include <iostream>

using namespace std;
int main(){
	int r, g, b;
	cin >> r >> g >> b;
	int max = 0;
	for(int mix = 0; mix < 3 && r >= mix && g >= mix && b >= mix; mix++){
		int v = mix + (r - mix) / 3 + (g - mix) / 3 + (b - mix) / 3;
		if( v > max )
			max = v;
	}
	cout << max << endl;
	return 0;
}