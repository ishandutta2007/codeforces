#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <set>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

const int maxn=3000;


int n,d,t[maxn];
string a[maxn],b[maxn];
set<pair<string,string> > s;
char c1[30],c2[30];


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	cin >> n >> d;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i] >> t[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (t[i]-t[j]>0 && t[i]-t[j]<=d && a[i]==b[j] && b[i]==a[j]) {
				pair<string,string> o;
				if (a[i]<b[i]) o=make_pair(a[i],b[i]);
				else o=make_pair(a[j],b[j]);
				s.insert(o);
			}
		}
	}
	cout << s.size() << endl;
	for (set<pair<string,string> > :: iterator it=s.begin(); it!=s.end(); it++ ){
		cout << it->first << ' ' << it->second << endl;
	}
    return 0;
}