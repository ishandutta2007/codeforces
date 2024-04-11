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
vector<int> q[33];
int id[33],r,s[33];
ll n,m;

int gcd(int x, int y) {
    while (x && y)
	if (x >= y) x %= y;
	else y %= x;
    return x+y;
}
int lcm(int x, int y) {
    return (x / gcd(x,y)) * y;
}

int week = 0;
int prod = 1;
int number = 0;

vector<int> decrypt(int x) {
    vector<int> res;
    for (int i=0;i<r;i++) {
	res.push_back(x % s[i]);
	x /= s[i];
    }
    return res;
}

int encrypt(vector<int> l) {
    int res = 0, koof = 1;
    for (int i=0;i<l.size();i++) {
	res = res + l[i] * koof;
	koof *= s[i];
    }
    return res;
}

vector<int> vec[222];
map<vector<int>,int> nums;

#define MOD 12345

struct cell {
    ll a[155][155],n;
    
    
} mat;

ll need;

cell operator *(cell& A, cell& B) {
	cell C;
	C.n = A.n;
	int n = C.n;
	for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++) {
		ll res = 0;
		for (int k=0;k<n;k++) res += A.a[i][k] * B.a[k][j];
		C.a[i][j] = res % MOD;
	    }
	return C;
    }

void write(cell& A) {
    int n = A.n;
    for (int i=0;i<n;i++) {
	for (int j=0;j<n;j++) cout << A.a[i][j] << " ";
	cout << endl;
    }
    cout << endl;
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> need >> m;
    while (m--) {
	char c = getchar();
	while (c < 'A' || c > 'Z') c = getchar();
	
	int num = c - 'A';
	int x; cin >> x;
	q[num].push_back(x);
    }
    
    
    for (int i=0;i<26;i++)
	if (q[i].size() != 0) {
	    int res = q[i][0];
	    for (int j=1;j<q[i].size();j++)
		res = lcm(res,q[i][j]);
	    s[r++] = res;
	    id[r-1] = i;
	    prod *= res;
	}
    
    for (int i=0;i<prod;i++) {
	vec[i] = decrypt(i);
	nums[ vec[i] ] = i;
    }
    
    mat.n = prod;
    for (int i=0;i<prod;i++) {
	vector<int> nw;
	for (int j=0;j<r;j++) {
	    nw = vec[i];
	    nw[j] = (nw[j] + 1) % s[j];
	    int num = nums[nw];
	    mat.a[i][num]++;
	}
    }
    
    cell ans;
    ans.n = prod;
    for (int i=0;i<prod;i++) ans.a[i][i] = 1;
    
    
    for (ll i=0; (((ll) 1) << i) <= need; i++) {
	if (need & (((ll) 1) << i)) {
	    ans = ans * mat;
	}
	//write(mat);
	mat = mat * mat;
    }
    
    
    ll lans = 0;
    for (int I=0;I<prod;I++) {
	bool good = 1;
	vector<int> w = vec[I];
	
	for (int i=0;i<r;i++) {
	    good = 0;
	    int num = id[i];
	    for (int j=0;j<q[num].size();j++)
		if ((w[i] % q[num][j]) == 0) good = 1;
	    if (!good) break;
	}
	
	if (good) lans = lans + ans.a[0][I];
    }
    
    cout << lans % MOD << endl;
    
    return 0;
}