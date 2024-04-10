#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;


int n,k[200],d[200][3],mx[3];
string s[200];
string a[200][200];
vector <string> ans[3];

bool c3(string &a) {
	return a[0]<a[1] && a[1]<a[3] && a[3]<a[4] && a[4]<a[6] && a[6]<a[7];
}

bool c1(string &a) {
	return a[0]==a[1] && a[1]==a[3] && a[3]==a[4] && a[4]==a[6] && a[6]==a[7];
}

bool c2(string &a) {
	return a[0]>a[1] && a[1]>a[3] && a[3]>a[4] && a[4]>a[6] && a[6]>a[7];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> k[i] >> s[i];
		for (int j=0; j<k[i]; j++) {
			cin >> a[i][j];
			if (c1(a[i][j])) 
				d[i][0]++;
			else if (c2(a[i][j])) 
				d[i][1]++;
			else //if (c3(a[i][j])) 
				d[i][2]++;
		}
		mx[0]=max(mx[0],d[i][0]);
		mx[1]=max(mx[1],d[i][1]);
		mx[2]=max(mx[2],d[i][2]);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++)
			if (d[i][j]==mx[j]) ans[j].push_back(s[i]);
	}
	
	cout << "If you want to call a taxi, you should call: ";
	for (int i=0; i<(int)ans[0].size()-1; i++) cout << ans[0][i] << ", ";
	cout << ans[0].back() << '.' << endl;

	cout << "If you want to order a pizza, you should call: ";
	for (int i=0; i<(int)ans[1].size()-1; i++) cout << ans[1][i] << ", ";
	cout << ans[1].back() << '.' << endl;

	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for (int i=0; i<(int)ans[2].size()-1; i++) cout << ans[2][i] << ", ";
	cout << ans[2].back() << '.' << endl;

	return 0;
}