#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long
	 
using namespace std;

#pragma comment(linker,"/STACK:64000000")

string str(int i) {
	stringstream ss;
	ss << i;
	string res="";
	ss >> res;
	return res;
}

const int maxn=1<<19, inf=1000000000;
const ll q=1000000007;
const double eps=1e-9;


int n,k;
ll ans;
int a[maxn];
map<int,int> m;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++)
		scanf("%d",&a[i]);
	a[n]=a[n-1];

	int r=0; m[a[0]]++;
	for (int l=0; l<n; m[a[l++]]--) {
		while (r<n && m[a[r]]<k) 
			m[a[++r]]++;
		if (m[a[r]]==k) ans+=n-r;
	}

	cout << ans;

	return 0;
}