#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=100100;
const double EPS=1e-9;
const int INF=1e9;

int n,len;
int prans=INF,prans1=-1;
int a[5][5];
char c[4][4*maxn];

int gauss (vector < vector<double> > a, vector<double> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}

vector<vector<double>> v;

void getmatrix(int y1,int y2,int y3) {
	v.resize(4,vector<double>(5,0));
	v[0][0]=1;
	v[1][0]=1; v[1][1]=1; v[1][2]=1; v[1][3]=1; v[1][4]=a[0][3];
	v[2][0]=-1; v[2][1]=-1; v[2][2]=1; v[2][3]=1; v[2][4]=a[1][3]-y1-y2;
	v[3][0]=1; v[3][1]=-1; v[3][2]=-1; v[3][3]=1; v[3][4]=a[2][3]-y2-y3;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i=0; i<3; i++) {
		for (int j=i+1; j<4; j++)
			cin >> a[i][j];
	}
	for (int i=0; i<4*maxn; i++) for (int k=0; k<4; k++) c[k][i]='a';

	for (int i=0; i<a[0][1]; i++) {c[1][i]='b'; len=max(len,i); }
	
	
	/*if (!(abs(a[0][2]-a[0][1])<=a[1][2] && a[1][2]<=a[0][1]+a[0][2]) || (abs(a[0][2]-a[0][1])-a[1][2])%2!=0) {
		cout << -1;
		return 0;
	}*/

	int l=0, r=a[0][1], x=-1;
	for (int i=0; i<=r; i++) {
		int k=i+abs(i+a[0][2]-a[0][1]);
		if (k==a[1][2]) {
			x=i; break;
		}
	}

	if (x==-1) {
		cout << -1; return 0;
	}

	for (int i=x; i-x<a[0][2]; i++) {
		c[2][i]='b';
		len=max(len,i);
	}
	
	if (a[0][2]==0) x=a[0][1];
	int x1=0, x2=x, x3=a[0][1], x4=x+a[0][2];
	int y1=x2-x1, y2=x3-x2, y3=x4-x3;

	getmatrix(y1,y2,y3);

	for (int i=0; i<=x2; i++) {
		v[0][4]=i;
		vector<double> ans;
		ans.resize(4);
		if (gauss(v,ans)==1) {
			bool ff=true;
			for (int j=0; j<4; j++) if (abs(ans[j]-(int)ans[j])>EPS || ans[j]<0) { ff=false; break; }
			if (ans[0]>x2) continue;
			if (ans[1]>x3-x2) continue;
			if (ans[2]>x4-x3) continue;
			if (ans[3]<prans && ff) {
				prans=ans[3];
				prans1=i;
			}
		}
	}

	if (prans1!=-1) {
		vector<double> ans;
		v[0][4]=prans1;
		ans.resize(4);
		gauss(v,ans);
		for (int i=0; i<ans[0]; i++)
			c[3][i]='b';
		for (int i=x2; i-x2<ans[1]; i++) {
			c[3][i]='b';
		}
		for (int i=x3; i-x3<ans[2]; i++) {
			c[3][i]='b';
		}
		for (int i=x4; i-x4<ans[3]; i++) {
			c[3][i]='b';
			len=max(len,i);
		}
	} else {cout << -1; return 0; }

	cout << len+1 << "\n";
	for (int i=0; i<4; i++) {
		for (int j=0; j<=len; j++)
			cout << c[i][j];
		cout << "\n";
	}
	return 0;
}