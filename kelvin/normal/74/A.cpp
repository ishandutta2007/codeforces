#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#define MAXNUM 55

using namespace std;

string name[MAXNUM];

int main() {
	int i,n,pos,neg,a,b,c,d,e,s,maxs;
	string str;
	cin >> n;
	maxs = -1000000000;
	for(i=0;i<n;i++) {
		cin >> name[i] >> pos >> neg >> a >> b >> c >> d >> e;
		s = pos*100 - neg*50 + a + b + c + d + e;
		if(s>maxs) {
			maxs = s;
			str = name[i];
		}
	}
	cout << str << endl;
	return 0;
}