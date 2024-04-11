#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int n, m, arr[505][505], sum[505][505] = {};
int main() {
	cin >> n >> m;
	f(i,1,n+1) {
  		f(j,1,m+1) {
      		cin >> arr[i][j];
      		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
    	}
  	}
	int mx = -999999999;
	f(i,1,n+1) {
  		f(j,1,m+1) {
    		int k = 1, s = arr[i][j];
    		while (i - k > 0 && i + k <= n && j - k > 0 && j + k <= m) {
        		s = sum[i + k][j + k] - sum[i - k - 1][j + k] - sum[i + k][j - k - 1] +
            	sum[i - k - 1][j - k - 1] - arr[i - k + 1][j - k] - s;
        		mx = max(mx, s);
      		  	k++;
      		}
    	}
  	}
  	cout << mx << endl;
}