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
#define N 333
struct pii {
    int x,y,c;
    
    pii() {x = y = c = 0;}
    pii(int ax, int ay, int ac) {
	x = ax; y = ay; c = ac;
    }
};

int w[2*N*N],number[2*N*N],real[2*N*N];
int n,m,a[N][N],b[N][N];
vector<int> colors;
vector<pii> g[2*N*N];
ll ans = 0;

int get_num(int x, int y) {
    int square = max(abs(x),abs(y));
    int len = square*2 + 1;
    int cur_num = len*len;
    
    if (x == -square) return cur_num + y - square;
    cur_num -= len-1;
    if (y == -square) return cur_num - x - square;
    cur_num -= len-1;
    if (x == square) return cur_num - y - square;
    cur_num -= len-1;
    return cur_num + x - square;
}

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

void un(int x, int y, int r) {
    x = fath(x); y = fath(y);
    if (g[x].size() > g[y].size()) swap(x,y);
    w[x] = y;
    real[y] = r;
    
    if (x == y) return;
    number[y] += number[x]; number[x] = 0;
    for (int i=0;i<g[x].size();i++) g[y].push_back( g[x][i] );
}

pii O;
bool cmp(pii a, pii b) {
    return get_num(a.y - O.y, O.x - a.x) < get_num(b.y - O.y, O.x - b.x);
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    colors.push_back(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) { 
	    cin >> a[i][j];
	    colors.push_back(a[i][j]);
	}
    
    for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
	    cin >> b[i][j];
	    if (b[i][j] != -1) colors.push_back(b[i][j]);
	}
    sort(colors.begin(),colors.end());
    colors.resize(unique(colors.begin(),colors.end()) - colors.begin());
    
    for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
	    a[i][j] = lower_bound(colors.begin(),colors.end(),a[i][j]) - colors.begin();
	    number[ a[i][j] ]++;
	    if (b[i][j] != -1) { 
		b[i][j] = lower_bound(colors.begin(),colors.end(),b[i][j]) - colors.begin();
		g[ a[i][j] ].push_back( pii(i,j,b[i][j]) );
	    }
	}
    
    for (int i=0;i<colors.size();i++) real[i] = w[i] = i;
    
    pii cur; cin >> cur.x >> cur.y; cur.c = b[cur.x][cur.y]; b[cur.x][cur.y] = -1;
    queue<pii> q; q.push(cur);
    
    while (!q.empty()) {
	cur = q.front(); q.pop();
	int panel_color = fath(a[cur.x][cur.y]);
	int real_panel_color = real[panel_color];
	int symbol_color = cur.c;
	if (real_panel_color == 0 || real_panel_color == symbol_color) continue;
	
	
	int score = number[ panel_color ];
	ans += score;
	
	O = cur;
	sort(g[panel_color].begin(),g[panel_color].end(),cmp);
	int lim = g[panel_color].size();
	for (int i=0;i<lim;i++) {
	    pii cand = g[panel_color][i];
	    if (b[cand.x][cand.y] != -1) { 
		q.push(cand);
		b[cand.x][cand.y] = -1;
	    }
	}
	g[panel_color].clear();
	
	un(panel_color,symbol_color,symbol_color);
    }
    
    cout << ans << endl;
    
    return 0;
}