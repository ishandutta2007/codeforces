#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

const double eps=1e-10;

struct point {
	int x,y;
	bool operator< (const point &p) {
		return x<p.x || x==p.x&&y<p.y;
	}
};

int n,m,k,p,ans;
string s;
point a[8],b[8];

double d(int i, int j) {
	return sqrt(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y)+0.0);
}

int find(int x) {
	for (int i=0; i<8; i++) if (b[i].x==a[x].x && b[i].y==a[x].y) return i;
}

bool check(int a0,int a1,int a2) {
	bool f=abs((a[a1].x-a[a0].x)*(a[a2].x-a[a1].x)+(a[a1].y-a[a0].y)*(a[a2].y-a[a1].y))<eps;
	return f;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	for (int i=0; i<8; i++) cin >> a[i].x >> a[i].y;
	for (int i=0; i<8; i++) b[i]=a[i];
	//sort(a,a+8);
	for (int i=0; i<40320; i++) {
		bool f=true;
		if (i==121) 
			i=i;
		if (abs(sqrt(sqr(a[0].x-a[2].x)+sqr(a[0].y-a[2].y)+0.0)-sqrt(sqr(a[1].x-a[3].x)+sqr(a[1].y-a[3].y)+0.0))>eps) f=false;
		if (abs(sqrt(sqr(a[4].x-a[6].x)+sqr(a[4].y-a[6].y)+0.0)-sqrt(sqr(a[5].x-a[7].x)+sqr(a[5].y-a[7].y)+0.0))>eps) f=false;
		if (abs(sqr(d(0,1))-d(0,1)*d(1,2))>eps) f=false;
		//if (abs((a[1].x-a[0].x)*(a[2].x-a[1].x)+(a[1].y-a[0].y)*(a[2].y-a[1].y))>0) f=false;
		//if (abs((a[5].x-a[4].x)*(a[6].x-a[5].x)+(a[5].y-a[4].y)*(a[6].y-a[5].y))>0) f=false;
		if (!(check(0,1,2) && check(1,2,3) && check(2,3,0) && check(3,0,1))) f=false;
		if (!(check(4,5,6) && check(5,6,7) && check(6,7,4) && check(7,4,5))) f=false;
		if (f) {
			cout << "YES" << endl;
			for (int i=0; i<4; i++) cout << find(i)+1 << ' '; cout << endl;
			for (int i=4; i<8; i++) cout << find(i)+1 << ' '; cout << endl;
			return 0;
		}
		next_permutation(a,a+8);
	}
	cout << "NO";
	return 0;
}