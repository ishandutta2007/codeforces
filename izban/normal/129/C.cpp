#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
using namespace std;

#define sqr(x) ((x)*(x))

struct typ {
	int x; int y; int t;
};

string a[9];
typ x; 
deque <typ> c;
int d[10][10][10];

void go(int x, int y, int t) {
	if (x>0 && y>0 && x<9 && y<9 && d[x][y][t+1]==0 && !(x+t>0 && x+t<=8 && a[x+t][y-1]=='s') && !(x+t+1<=8 && a[x+t+1][y-1]=='s')) {
		if (x==7 && y==1 && t==7)
			x=x;
		typ u; u.x=x; u.y=y; u.t=t+1;
		c.push_back(u);
		d[u.x][u.y][u.t]=1;
	}
}

int main() {

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);       
        freopen("output.txt", "w", stdout);
#endif
		for (int i=8; i>=1; i--) {
			cin >> a[i];
			for (int j=0; j<8; j++) 
				if (a[i][j]=='S') a[i][j]='s';
		}
		x.x=1; x.y=1; x.t=0;
		c.push_back(x);
		bool f=false;
		while (c.size()) {
			x=c.front();

			if (x.t==9) {
				f=true; break;
			}
			if (x.t==7)
				x=x;
			go(x.x+1,x.y,x.t);
			go(x.x-1,x.y,x.t);
			go(x.x,x.y+1,x.t);
			go(x.x,x.y-1,x.t);
			go(x.x+1,x.y+1,x.t);
			go(x.x+1,x.y-1,x.t);
			go(x.x-1,x.y+1,x.t);
			go(x.x-1,x.y-1,x.t);
			go(x.x,x.y,x.t);
			c.pop_front();
		}
		//c.clear();
		if (f) cout << "WIN";
		else cout << "LOSE";
        return 0;
}