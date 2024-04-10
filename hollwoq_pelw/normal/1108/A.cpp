#include<bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	while(q--){
	    int x,y,z,t;
	    cin >> x >> y >> z >> t;
	    if (x != z) cout << x << ' ' << z;
	    else cout << y << ' ' << z;
	    cout << endl;
	}
}