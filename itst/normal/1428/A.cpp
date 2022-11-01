#include<bits/stdc++.h>
using namespace std;

int main(){
	int T , x1 , y1 , x2 , y2;
	for(cin >> T ; T ; --T){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << abs(x1 - x2) + abs(y1 - y2) + ((x1 != x2) && (y1 != y2)) * 2 << endl;
	}
	return 0;
}