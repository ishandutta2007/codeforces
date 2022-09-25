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

const int maxn=1<<10, inf=1000000007;
const double eps=1e-9;

int n,t1,t2,k;
pair<int,int> a[maxn];
vector<pair<double,int>> ans;

bool cmp(pair<double,int> &a, pair<double,int> &b) {
	return a.first-b.first>eps || abs(b.first-a.first)<eps && a.second<b.second;
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

	cin >> n >> t1 >> t2 >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
		double cans1=(t1*a[i].first)*(100-k)/100.0+t2*a[i].second;
		double cans2=(t1*a[i].second)*(100-k)/100.0+t2*a[i].first;
		ans.push_back(make_pair(max(cans1,cans2),i+1));
	}
	sort(ans.begin(),ans.end(),cmp);
	for (int i=0; i<ans.size(); i++)
		printf("%d %.2lf\n",ans[i].second,ans[i].first);

    return 0;
}