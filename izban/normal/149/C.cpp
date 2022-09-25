#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m,p,ans,s1,s2,k[100000],cnt;
string s;

pair<int,int> a[100000];
vector<int>ans1,ans2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second=i+1;
	}
	sort(a,a+n);
	for (int i=0; i<n; i++) {
		if (s1<s2) {
			k[i]=1;
			s1+=a[i].first;
			cnt++;
		} else if (s2<s1) {
			k[i]=2;
			s2+=a[i].first;
		} else if (cnt<=i-cnt) {
			k[i]=1;
			s1+=a[i].first;
			cnt++;
		} else {
			k[i]=2;
			s2+=a[i].first;
		}
	}
	for (int i=0; i<n; i++) {
		if (k[i]==1) ans1.push_back(a[i].second);
		else ans2.push_back(a[i].second);
	}
	cout << ans1.size() << endl;
	for (int i=0; i<ans1.size(); i++) cout << ans1[i] << ' '; cout << endl;
	cout << ans2.size() << endl;
	for (int i=0; i<ans2.size(); i++) cout << ans2[i] << ' '; cout << endl;
	return 0;
}