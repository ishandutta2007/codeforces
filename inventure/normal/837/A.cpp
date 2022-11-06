#include <bits/stdc++.h>

using namespace std;

int n ;
string s;

int main( int argc , char * argv[] ){
	cin >> n ;
	getchar( );
	getline( cin , s );
	int ans = 0;
	for(int i = 0 ; i < s.size() ; ){
		if( s[i] == ' ' ){
			++ i;
			continue;
		}
		string t;
		int j = i , ret = 0;
		while( j < s.size() && s[j] != 32 )
			t.push_back( s[j++] );
		for(auto && it : t)
			ret += isupper( it );
		ans = max( ans , ret );
		i = j;
	}
	cout << ans << endl;
	return 0;
}