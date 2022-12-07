#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> lens;
char w[111111];
int n,m;

int main() {
    //freopen("in","r",stdin);
    
    cin >> n; cin.ignore();
    gets(w);
    m = strlen(w);
    
    int cur = 0, wait = 1;
    for (int i=0;i<m;i++) {
	char c = w[i];
	if (c == ' ' && wait) {
	    wait = 0;
	    continue;
	}
	
	cur++;
	if (c == '.' || c == '?' || c == '!') {
	    lens.push_back(cur);
	    if (cur > n) {
		cout << "Impossible" << endl;
		return 0;
	    }
	    wait = 1;
	    cur = 0;
	    continue;
	}
    }
    
    int ans = 0, left = n;
    for (int i=0;i<lens.size();i++) {
	int need = lens[i]; if (left != n) need++;
	if (need <= left) {
	    left -= need;
	    continue;
	}
	if (left != n) need--;
	left = n - need;
	ans++;
    }
    if (left != n) ans++;
    
    cout << ans << endl;
    
    return 0;
}