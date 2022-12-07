#include <stdio.h>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
struct cell {
	int g,r,h,s;
	
	cell(int ag, int ar, int ah, int as): g(ag), r(ar), h(ah), s(as) {};
	
	int mn() {
		return min(min(g,r),min(h,s));
	};
	
	bool operator <(const cell& A) const {
		if (g != A.g) return g < A.g;
		if (r != A.r) return r < A.r;
		if (h != A.h) return h < A.h;
		return s < A.s;
	}
};
set<cell> T,W;
bool cg,cr,ch,cs;

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int n; scanf("%d",&n);
	T.insert(cell(0,0,0,0));
	while (n--) {
		char c = getchar();
		while (c != 'G' && c != 'H' && c != 'R' && c != 'S' && c != '?') c = getchar();
		
		for (set<cell>::iterator it=T.begin();it!=T.end();it++) {
			cell cur = *it; int mn = cur.mn();
			if (c == 'G' || c == '?' && cur.g == mn) {
				cur.g++;
				W.insert(cur);
				cur.g--;
			}
			if (c == 'H' || c == '?' && cur.h == mn) {
				cur.h++;
				W.insert(cur);
				cur.h--;
			}
			if (c == 'R' || c == '?' && cur.r == mn) {
				cur.r++;
				W.insert(cur);
				cur.r--;
			}
			if (c == 'S' || c == '?' && cur.s == mn) {
				cur.s++;
				W.insert(cur);
				cur.s--;
			}
		}
		
		T = W; W.clear();
		//cout << T.size() << endl;
	}
	
	
	for (set<cell>::iterator it=T.begin();it!=T.end();it++) {
		cell cur = *it; int mn = cur.mn();
		if (cur.g == mn) cg = 1;
		if (cur.h == mn) ch = 1;
		if (cur.r == mn) cr = 1;
		if (cur.s == mn) cs = 1;
	}
	
	if (cg) puts("Gryffindor");
	if (ch) puts("Hufflepuff");
	if (cr) puts("Ravenclaw");
	if (cs) puts("Slytherin");

	return 0;
}