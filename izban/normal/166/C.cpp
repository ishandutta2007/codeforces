#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=1010;

string s;
int n, a[maxn], k, x;
bool f;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> x;
	for (int i=0; i<n; i++) 
		cin >> a[i], f|=a[i]==x;
	k=n; 
	if (!f) a[k++]=x;
	sort(a,a+k);
	int nw=a[(n-1)>>1]>x? 0 : 100000;
	while (a[(k-1)>>1]!=x) {
		a[k]=nw;
		int cur=k++;
		while (cur && a[cur]<a[cur-1]) 
			swap(a[cur],a[cur-1]), cur--;
	}
	cout << k-n;
	return 0;
}