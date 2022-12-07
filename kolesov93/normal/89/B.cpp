#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define N 1111
struct cell {
    long long h,w,type,spacing,border;
    string nm;
    
    bool operator <(const cell& A) const {
	return nm < A.nm;
    }
} a[N];
long long ke,kv,fir[N],tov[N],next[N];
bool u[N];
map<string,long long> mq;

void add(long long x,long long y) {
    next[++ke] = fir[x]; fir[x] = ke; tov[ke] = y;
} 

char buffer[111111];

long long get_num(string& s) {
    long long res = 0; 
    long long st = 0;
    s = s + ".";
    for (long long i=0;i<s.length();i++) {
	if (st == 0 && s[i] >= '0' && s[i] <= '9') st = 1;
	if (st == 1) {
	    if (s[i] >= '0' && s[i] <= '9') res = res*10 + s[i] - '0';
	    else {
		s = s.substr(i);
		return res;
	    }
	}
    }
    return res;
}

void rec(long long x) {
    if (u[x]) return;
    u[x] = 1;
    long long sons = 0, mxh=0, mxw=0, sh = 0, sw = 0;
    
    for (long long t=fir[x];t;t=next[t]) {
	rec(tov[t]);
	sons++;
	mxw = max(mxw,a[tov[t]].w);
	mxh = max(mxh,a[tov[t]].h);
	sh += a[tov[t]].h;
	sw += a[tov[t]].w;
    }
    
    if (sons) {
	if (a[x].type == 1) {
	    a[x].w = mxw + a[x].border * 2;
	    a[x].h = sh + (sons-1) * a[x].spacing + a[x].border * 2;
	} else {
	    a[x].h = mxh + a[x].border * 2;
	    a[x].w = sw + (sons-1) * a[x].spacing + a[x].border * 2;
	}
    }
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    long long _T;
    cin >> _T; cin.ignore();
    while (_T--) {
	gets(buffer);
	string s = buffer;
	
	if (s.length() > 7 && s.substr(0,7) == "Widget ") {
	    s = s.substr(7);
	    string nm = "";
	    long long br = s.find('(');
	    nm = s.substr(0,br);
	    //cout << nm << endl;
	    long long w = get_num(s);
	    long long h = get_num(s);
	    //cout << w << " " << h << endl;
	    
	    mq[nm] = ++kv;
	    a[kv].nm = nm;
	    a[kv].w = w; a[kv].h = h;
	    a[kv].spacing = a[kv].border = 0;
	    a[kv].type = 0;
	    continue;
	} 
	
	if (s.length() > 5 && s.substr(0,5) == "VBox ") {
	    s = s.substr(5);
	    string nm = "";
	    nm = s.substr(0);
	    //cout << nm << endl;
	    
	    mq[nm] = ++kv;
	    a[kv].nm = nm;
	    a[kv].spacing = a[kv].border = 0;
	    a[kv].type = 1;
	    continue;
	}
	
	if (s.length() > 5 && s.substr(0,5) == "HBox ") {
	    s = s.substr(5);
	    string nm = "";
	    nm = s.substr(0);
	    //cout << nm << endl;
	    
	    mq[nm] = ++kv;
	    a[kv].nm = nm;
	    a[kv].spacing = a[kv].border = 0;
	    a[kv].type = 2;
	    continue;
	}
	
	long long fath;
	string fnm = s.substr(0,s.find('.'));
	fath = mq[fnm];
	
	s = s.substr(s.find('.')+1);
	if (s[0] == 'p') {
	    s = s.substr(5,s.length() - 6);
	    //cout << fnm << "-->" << s << endl;
	    
	    long long son = mq[s];
	    
	    add(fath,son);
	    
	    continue;
	}
	
	if (s[4] == 'b') {
	    long long br = get_num(s);
	    a[fath].border = br;
	    continue;
	}
	
	a[fath].spacing = get_num(s);
    }
    
    for (long long i=1;i<=kv;i++) 
	if (!u[i]) rec(i);
    
    sort(a+1,a+kv+1);
    for (long long i=1;i<=kv;i++) cout << a[i].nm << " " << a[i].w << " " << a[i].h << endl;
	
    return 0;
}