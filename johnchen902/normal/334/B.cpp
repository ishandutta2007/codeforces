#include <iostream>
#include <array>
#include <algorithm>
#include <utility>

#define test(X) if(!(X))return false

using namespace std;
bool check(const array<pair<int,int>, 8>& pairs){
	//              01234567
	// check for x: aaabbccc
	{
		int a = pairs[0].first;
		int b = pairs[3].first;
		int c = pairs[5].first;
		test(a < b && b < c);
		test(a == pairs[1].first && a == pairs[2].first);
		test(b == pairs[4].first);
		test(c == pairs[6].first && c == pairs[7].first);
	}
	//              01234567
	// check for y: abcacabc
	{
		int a = pairs[0].second;
		int b = pairs[1].second;
		int c = pairs[2].second;
		test(a < b && b < c);
		test(a == pairs[3].second && a == pairs[5].second);
		test(b == pairs[6].second);
		test(c == pairs[4].second && c == pairs[7].second);
	}
	return true;
}
int main(){
	array<pair<int,int>, 8> pairs;
	for(int i = 0; i < 8; i++){
		int x, y;
		cin >> x >> y;
		pairs[i] = make_pair(x, y);
	}
	sort(pairs.begin(), pairs.end());
	cout << (check(pairs) ? "respectable" : "ugly") << endl;
	return 0;
}