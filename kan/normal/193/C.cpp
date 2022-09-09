#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxlen=4e5;

char a1[maxlen],a2[maxlen],a3[maxlen],a4[maxlen];
int h21,h31,h32,h41,h42,h43;

inline void bad()
{
	cout << -1 << endl;
	exit(0);
}

int main()
{
	cin >> h21 >> h31 >> h41 >> h32 >> h42 >> h43;
	for (int i=0;i<maxlen;i++) a1[i]='a',a2[i]='a',a3[i]='a',a4[i]='a';
	int x=h21+h32-h31;
	if ((x%2)!=0) bad();
	x=x/2;
	int y=h21-x;
	int z=h31-y;
	if (x<0 || y<0 || z<0) bad();
	assert(x+z==h32);
	for (int i=0;i<h21;i++) a2[i]='b';
	for (int i=x;i<x+y+z;i++) a3[i]='b';
	if (((h41-h42+x+y)%2)!=0) bad();
	if (((h43+h42-x-z)%2)!=0) bad();
	if (((h43+h41-y-z)%2)!=0) bad();
	for (int b7=0;b7<maxlen-x-y-z;b7++)
	{
		int b5=(2*b7+2*z+x+y-h41-h42)/2;
		int b6=z-b5;
		int b3=(h43+h42-2*b7-x-z)/2;
		int b4=y-b3;
		int b1=(h43+h41-2*b7-y-z)/2;
		int b2=x-b1;
		if (b1<0 || b2<0 || b3<0 || b4<0 || b5<0 || b6<0) continue;
		for (int i=0;i<b1;i++) a4[i]='b';
		for (int i=b1+b2+b3;i<b1+b2+b3+b4;i++) a4[i]='b';
		for (int i=b1+b2+b3+b4+b5;i<b1+b2+b3+b4+b5+b6+b7;i++) a4[i]='b';
		cout << b1+b2+b3+b4+b5+b6+b7 << endl;
		for (int i=0;i<b1+b2+b3+b4+b5+b6+b7;i++) cout << a1[i];
		cout << endl;
		for (int i=0;i<b1+b2+b3+b4+b5+b6+b7;i++) cout << a2[i];
		cout << endl;
		for (int i=0;i<b1+b2+b3+b4+b5+b6+b7;i++) cout << a3[i];
		cout << endl;
		for (int i=0;i<b1+b2+b3+b4+b5+b6+b7;i++) cout << a4[i];
		cout << endl;
		return 0;
	}
	bad();
	return 0;
}