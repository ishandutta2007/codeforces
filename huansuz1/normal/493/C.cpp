#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define mk make_pair
#define f first
#define s second
#define NN int(3e5)
const int Ma = 10000;

int a[NN], b[NN], n, m, x[NN], y[NN];
int N, M;
int ans;
int ansa;
int ansb;

int main(){
//	freopen("in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	x[i] = a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    	y[i] = b[i];
    }

    sort(a, a + n);
    sort(b, b + m);
    sort(y, y + m);
    sort(x, x + n);

    M = unique(y, y + m) - y;

    ans = n * 3 - m*3;
    ansa = n*3;
    ansb = m*3;

    for (int i = 0; i < M; i++) {
    	int p = y[i];
    	int l = -1;
    	int r = n;
    	while (r - l > 1) {
    	     int mid = (l + r) / 2;
    	     if (a[mid] > p)
    	     	r = mid;
    	     else
    	     	l = mid;
    	}	
    	int g = r;
    	l = -1;
    	r = m;
    	while (r - l > 1) {
    	 	int mid = (l + r) / 2;
    	 	if (b[mid] > p)
    	 		r = mid;
    	 	else
    	 		l = mid;
    	}
    	if (ans < (n-g)*3+g*2-(m-r)*3-r*2) {
    	 	ans = (n-g)*3+g*2-(m-r)*3-r*2;
       	 	ansa = (n-g)*3+g*2;
    	 	ansb = (m-r)*3 + r*2;
     	} else if (ans == (n-g)*3+g*2-(m-r)*3-r*2&&ansa < (n-g)*3+g*2) {
    	 	ansa = (n-g)*3+g*2;
    	 	ansb = (m-r)*3 + r*2;
    	}
    //	cerr << p << " " << g << " " << r << endl; 

    }
    cout << ansa << ":" << ansb << endl;
	return 0;      
}