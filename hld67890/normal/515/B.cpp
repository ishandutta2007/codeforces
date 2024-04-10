#include <iostream>

using namespace std;

int n , m;
bool f1[102] , f2[102];
void work () {
	int i , j , f , a  , b;
	cin >> n >> m;
	cin >> a;
	for ( i = 0 ; i < a ; i++ ) { cin >> b; f1[b] = 1; }
	cin >> a;
	for ( i = 0 ; i < a ; i++ ) { cin >> b; f2[b] = 1; }
	i = 0; j = 0; f = 0;
	while ( 1 ) {
		if ( f1[i] == 1 && f2[j] == 0 ) f2[j] = f = 1;
		if ( f1[i] == 0 && f2[j] == 1 ) f1[i] = f = 1;
		i++; i = i % n;
		j++; j = j % m;
		if ( i == 0 && j == 0 ) {
			if ( !f )
				break;
			f = 0;
		}
	}
	f = 1;
	for ( i = 0 ; i < n ; i++ ) if ( f1[i] == 0 ) f = 0;
	for ( i = 0 ; i < m ; i++ ) if ( f2[i] == 0 ) f = 0;
	if ( f == 1 ) cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main () {
	work ();
	return 0;
}