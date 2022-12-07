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
#define N 111
#define M 1111
struct item {
    string name;
    int capacity,type;
    
    vector<string> need;
    vector<string> already;
    
    int a[3];
} a[N];
struct cell {
    int bonus,type;
    string name;
    bool busy;
    int home;
    
    bool operator <(const cell& A) const {
	return bonus > A.bonus;
    }
};
int n,k;
vector<int> g[3];
vector<cell> b[3];
int busy[N],sons[N];
map<string,int> itemId;

int s[3][M];

struct sans {
    int id[3];
    int a[3];
    
    bool operator <(const sans& A) const {
	for (int i=0;i<3;i++)
	    if (a[i] != A.a[i]) return a[i] < A.a[i];
	return false;
    }
} ans;

bool test = false;

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    int n; cin >> n; 
    test = false;
    
    
    for (int i=0;i<n;i++) {
	cin.ignore();
	string cl;
	cin >> a[i].name >> cl;
	if (cl[0] == 'w') a[i].type = 0;
	if (cl[0] == 'a') a[i].type = 1;
	if (cl[0] == 'o') a[i].type = 2;
	cin >> a[i].a[0] >> a[i].a[1] >> a[i].a[2] >> a[i].capacity;
	itemId[ a[i].name ] = i;
    }
    for (int i=0;i<n;i++) 
	g[ a[i].type ].push_back(i);
    
    int k; cin >> k;
    while (k--) {
	cin.ignore();
	cell cur;
	cur.busy = false;
	string cl,home;
	cin >> cur.name >> cl >> cur.bonus >> home;
	
	if (cl[0] == 'g') cur.type = 0;
	if (cl[0] == 's') cur.type = 1;
	if (cl[0] == 'p') cur.type = 2;
	
	int id = itemId[ home ];
	busy[id]++;
	a[id].already.push_back(cur.name);
	
	if (cur.type == a[id].type) sons[id] += cur.bonus;
	
	b[cur.type].push_back(cur);
    }
    
    bool cool = false;
    for (int i=0;i<n;i++)
	if (busy[i] < a[i].capacity) cool = true;
    
    if (cool) {
	for (int i=0;i<3;i++) { 
	    if (b[i].size() == 0) continue;
	    sort(b[i].begin(),b[i].end());
	    
	    s[i][0] = b[i][0].bonus;
	    for (int j=1;j<b[i].size();j++)
		s[i][j] = s[i][j-1] + b[i][j].bonus;
	    for (int j=b[i].size();j<=10;j++) s[i][j] = s[i][j-1];
	}
	if (test) return 5;
	
	for (int i=0;i<3;i++) ans.a[i] = -100;
	for (int i=0;i<g[0].size();i++)
	    for (int j=0;j<g[1].size();j++)
		for (int k=0;k<g[2].size();k++) {
		    sans res;
		    res.id[0] = g[0][i]; res.id[1] = g[1][j]; res.id[2] = g[2][k];
		    for (int q=0;q<3;q++) res.a[q] = 0;
		    
		    for (int q=0;q<3;q++)
			if (a[ res.id[q] ].capacity != 0)
			    res.a[q] = a[ res.id[q] ].a[ q ] + s[q][ a[ res.id[q] ].capacity - 1 ];
			else res.a[q] = a[ res.id[q] ].a[ q ];
		    
		    if (ans < res) ans = res;
		}
	if (test) return 4;
	
	for (int i=0;i<3;i++) {
	    int num = ans.id[i];
	    
	    int lim = min((int) b[i].size(), a[num].capacity);
	    for (int j=0;j<lim;j++) { 
		a[num].need.push_back( b[i][j].name );
		b[i][j].busy = true;
	    }
	}
	if (test) return 3;
	
	vector<string> free;
	for (int i=0;i<3;i++)
	    for (int j=0;j<b[i].size();j++)
		if (!b[i][j].busy) free.push_back(b[i][j].name);
	
	if (test) return 2;
	for (int i=0;i<3;i++) {
	    int num = ans.id[i];
	    while (free.size() > 0 && a[num].need.size() < a[num].capacity) {
		a[num].need.push_back(free[ (int) free.size() - 1 ]);
		free.pop_back();
	    }
	}
	
	if (test) return 1;
	for (int i=0;i<3;i++) {
	    int num = ans.id[i];
	    cout << a[num].name << " " << a[num].need.size();
	    for (int j=0;j<a[num].need.size();j++) cout << " " << a[num].need[j];
	    cout << endl;
	}
    } else {
	
	for (int i=0;i<3;i++) {
	    int num = g[i][0];
	    for (int j=0;j<g[i].size();j++) {
		int cand = g[i][j];
		if (a[cand].a[i] + sons[cand] > a[num].a[i] + sons[num]) num = cand;
	    }
	    
	    cout << a[num].name << " " << a[num].already.size();
	    for (int j=0;j<a[num].already.size();j++) cout << " " << a[num].already[j];
	    cout << endl;
	}
	
    } 
	
    return 0;
}