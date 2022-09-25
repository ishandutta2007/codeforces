#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;
long long a[50][50];
long long h[50],v[50],sh[50],sv[50];
long long A,B,C;
long long n,m,ans;
bool f;
bool chek(long long a,long long b,long long c) {
	if (min(A,min(B,C))==min(a,min(b,c)) && max(A,max(B,C))==max(a,max(b,c)) && (A+B+C-min(A,min(B,C))-max(A,max(B,C))==a+b+c-min(a,min(b,c))-max(a,max(b,c)))) {
		return true;
	}
	return false;
}
bool checkh(long long x) {
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n-1; j++)
			if (chek(sh[i],sh[j]-sh[i],sh[n-1]-sh[j])) {
				ans++;
			}
	return false;
}
bool checkv(long long x) {
	for (int i=0; i<m-1; i++)
		for (int j=i+1; j<m-1; j++) 
			if (chek(sv[i],sv[j]-sv[i],sv[m-1]-sv[j])) {
				ans++;
			}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
	cin >> n >> m; ans=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
			h[i]+=a[i][j];
			v[j]+=a[i][j];
		}
	}
	sh[0]=h[0];
	for (int i=1; i<n; i++) sh[i]=sh[i-1]+h[i];
	sv[0]=v[0];
	for (int i=1; i<m; i++) sv[i]=sv[i-1]+v[i];
	cin >> A >> B >> C;
	if (checkh(0)) ans=ans;
	if (checkv(0)) ans=ans;
	cout << ans;
	return 0;
}