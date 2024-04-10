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

const int maxn=1<<17, inf=1000000000;
const ll q=1000000007;
const double eps=1e-9;


int n,k,ans;
ll m,s1,s2;
int a[maxn],b[maxn];
map<int,int> mp;


int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n >> k >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b,b+n-1);
	reverse(b,b+n-1);
	for (int i=0; i<k-1; i++)
		s1+=b[i];
	s2=s1+b[k-1];
	for (int i=0; i<n; i++) {
		if (!mp[b[i]])
			mp[b[i]]=i+1;
	}

	ans=n;
	for (int i=0; i<n-1; i++) {
		ll u=0;
		if (mp[a[i]]<k) 
			u=s2-a[i];
		else
			u=s1;
		if (u+a[i]>m) {
			ans=i+1;
			break;
		}
	}
	cout << ans;
	return 0;
}