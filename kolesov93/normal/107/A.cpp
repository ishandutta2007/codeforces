#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;
int n,p;
bool u[1111];
int f[1111];
int to[1111];
int d1[1111],d2[1111];
struct cell {
    int a,b,c;
    
    bool operator <(const cell& A) const {
	return a < A.a;
    }
};


int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> n >> p;
    while (p--) {
	int a,b,c; cin >> a >> b >> c;
	d1[a]++; d2[b]++;
	to[a] = b;
	f[a] = c;
    }
    
    vector<cell> ans;
    for (int i=1;i<=n;i++) 
	if (d1[i] == 1 && d2[i] == 0) {
	    int cur = f[i];
	    int j = i;
	    while (d1[j]) {
		cur = min(cur,f[j]);
		j = to[j];
	    }
	    cell t;
	    t.a = i;
	    t.b = j;
	    t.c = cur;
	    ans.push_back(t);
	}
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
    
    
    return 0;
}