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
int a[6][5] = {{5,1,2,3,4},{3,5,2,0,4},{4,0,1,5,3},{1,5,4,0,2},{2,3,5,1,0},{0,4,3,2,1}};

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    string w; cin >> w;
    sort(w.begin(),w.end());
    set<string> q;
    do {
	bool cool = 1;
	
	//if (w == "BOBOOO")
	  //  cout << w << w << endl;
	
	string t = w;
	for (int c=0;c<6;c++) {
	    t[0] = w[c];
	    t[5] = w[a[c][0]];
	    for (int i=1;i<=4;i++) {
		int n = i;
		for (int j=1;j<=4;j++) {
		    t[j] = w[ a[c][n] ];
		    n++;
		    if (n == 5) n = 1;
		}
		
		if (q.find(t) != q.end()) {
		    cool = 0;
		    break;
		}
	    }
	    
	}
	
	if (cool) { 
	    q.insert(w);
	    //cout << "Cool: " << w << endl;
	}
    } while (next_permutation(w.begin(),w.end()));
    
    cout << q.size() << endl;
    //for (set<string>::iterator i=q.begin();i!=q.end();i++) 
	//cout << *i << endl;
    
    return 0;
}