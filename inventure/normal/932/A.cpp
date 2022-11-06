#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 50;

string s;

int main( int argc , char * argv[] ){
	cin >> s;
	cout << s;
	reverse( s.begin() , s.end() );
	cout << s << endl;
	return 0;
}