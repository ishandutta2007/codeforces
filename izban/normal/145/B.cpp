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

const int maxn=0;

int a[5];
string s;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	for (int i=1; i<5; i++) cin >> a[i];
	if (abs(a[3]-a[4])>1) {
		cout << -1;
		return 0;
	}
	if (a[3]<a[4]) {
		if (a[1]<a[4] || a[2]<a[4]) {
			cout << -1;
			return 0;
		}
		if (a[4]==1) {
			for (int i=0; i<a[2]-1; i++)
				s+='7';
			s+="74";
			for (int i=0; i<a[1]-1; i++)
				s+='4';
		} else {
			s+="74";
			for (int i=0; i<a[1]-a[4]; i++) 
				s+='4';
			for (int i=0; i<a[4]-2; i++) 
				s+="74";
			s+='7';
			for (int i=0; i<a[2]-a[4]; i++)
				s+='7';
			s+='4';
		}
	}
	if (a[3]==a[4]) {
		if (a[1]<a[3] || a[2]<a[3] || (a[1]<a[3]+1 && a[2]<a[3]+1)) {
			cout << -1;
			return 0;
		}
		if (a[1]>=a[3]+1) {
		for (int i=0; i<a[1]-a[3]-1; i++) 
			s+='4';
		for (int i=0; i<a[3]; i++) 
			s+="47";
		for (int i=0; i<a[2]-a[3]; i++) 
			s+='7';
		s+='4';
		} else {
			for (int i=0; i<a[3]; i++) 
				s+="74";
			for (int i=0; i<a[2]-a[3]; i++) s+='7';
		}
	}
	if (a[3]>a[4]) {
		if (a[1]<a[3] || a[2]<a[3]) {
			cout << -1; return 0;
		}
		for (int i=0; i<a[1]-a[3]; i++) 
			s+='4';
		for (int i=0; i<a[3]; i++) 
			s+="47";
		for (int i=0; i<a[2]-a[3]; i++) 
			s+='7';
	}
	cout << s;
	return 0;
}