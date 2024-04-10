#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0;int f = 1;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x *= f;
}
const int N = 100050;
ll n, a[N], ans;
int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(a[i]);
	for (int i = 1;i <= n; i++) {
		if (a[i+1] > a[i]) 
			ans += (a[i+1] - a[i]) * a[i];
		else ans += (n-a[i]+1) * (a[i] - a[i+1]);
	}
	cout << ans << endl;
	return 0;
}