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
typedef long double lf;
lf ax,ay,bx,by,cx,cy;

void rot(lf& x, lf& y, lf ang) {
    lf nx = x*cos(ang) - y*sin(ang);
    lf ny = x*sin(ang) + y*cos(ang);
    x = nx; y = ny;
}

lf myabs(lf x) {
    if (x < 0) return -x;
    return x;
}

bool doit(lf ax, lf ay) {
    if (fabs(cx) < 1e-10) 
	return fabs(ax-bx) < 1e-5 && fabs(ay-by) < 1e-5;
    
    ax += ((ll) ((bx - ax) / cx)) * cx;
    for (int i=0;i<5;i++)
	if (fabs(ax + myabs(cx) - bx) < fabs(ax - bx)) ax += myabs(cx);
    for (int i=0;i<100;i++)
	if (fabs(ax - myabs(cx) - bx) < fabs(ax - bx)) ax -= myabs(cx);

    ay += ((ll) ((by - ay) / cx)) * cx;
    for (int i=0;i<5;i++)
	if (fabs(ay + myabs(cx) - by) < fabs(ay - by)) ay += myabs(cx);
    for (int i=0;i<5;i++)
	if (fabs(ay - myabs(cx) - by) < fabs(ay - by)) ay -= myabs(cx);

     
    if (myabs(ax - bx) < 1e-5 && myabs(ay - by) < 1e-5) return true;
    return false;
}

void rot2(lf& x, lf& y) {
    lf nx = -y, ny = x;
    x = nx; y = ny;
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    
    lf ang = -atan2(cy,cx);
    rot(ax,ay,ang);
    rot(bx,by,ang);
    rot(cx,cy,ang); 
    
    for (int i=0;i<10;i++) {
	rot2(ax,ay);
	if (doit(ax,ay)) {
	    puts("YES");
	    return 0;
	}
    }
    
    puts("NO");
    
    return 0;
}