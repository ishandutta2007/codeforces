#include <bits/stdc++.h>

using namespace std;

string s;

int main( int argc , char * argv[] ){
	cin >> s;
	int ans = 0;
	for(int i = 0 ; i < s.size() ; ++ i){
		if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
			++ ans;
		else if( '0' <= s[i] && s[i] <= '9' && ( s[i] - '0' ) % 2 == 1 )
			++ ans;
	}
	cout << ans << endl;
	return 0;
}