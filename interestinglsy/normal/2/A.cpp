#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <string>
using namespace std;

map<string,int> mp , t;
int n;
string s[1004];
int sc[1004];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> s[i] >> sc[i];
		mp[s[i]] = mp[s[i]] + sc[i];
	}

	int mx = 0;
	for( int i = 1 ; i <= n ; i++ ){
		mx = max( mx , mp[s[i]] );
	}

	int i;
	for( i = 1 ; mp[s[i]] < mx  ||  ( t[s[i]] += sc[i] ) < mx ; i++ );
	cout << s[i] << endl;

	return 0;
}