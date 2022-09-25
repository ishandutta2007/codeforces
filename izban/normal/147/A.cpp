#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <ctime>
#include <set>
#include <map>
#include <queue>

using namespace std;


#define sqr(x) ((x)*(x))
#define ll long long

string a,b;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	getline(cin,a);
	for (int i=0; i<a.length(); i++) {
		//if (!(a[i]==' ' && (a[i+1]==' ' || a[i+1]==',' || a[i+1]=='.' || a[i+1]=='?' || a[i+1]=='!'))) b+=a[i];
		if (a[i]==' ') continue;
		if (a[i]>='a' && a[i]<='z' && !(i==0 || (a[i-1]>='a' && a[i-1]<='z'))) b+=' ';
		b+=a[i];
		//if (a[i]==',' || a[i]=='.' || a[i]=='?' || a[i]=='!' && a[i]==b[b.length()-1]) b+=' ';
	}

	cout << b;
	return 0;
}