#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>
using namespace std;

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int n,m,l,r;
	cin >> n >> m;
	l = 1; r = n;
	bool cool = 1;
	while (m--) {
		string s;
		cin >> s;
		cin >> s; cin >> s;
		bool left=1;
		if (s == "right") left = 0;
		cin >> s;
		int x,nl,nr; cin >> x;
		if (left) {
			nl = 1; nr = x-1;
		} else {
			nl = x+1; nr = n;
		}
		
		
		l = max(l,nl); r = min(r,nr);
		if (nl > nr || l > r) cool = 0; 
	}
	
	if (!cool) cout << "-1" << endl;
	else cout << r-l+1 << endl;
	
	return 0;
}