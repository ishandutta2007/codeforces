#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define INF 9999999
#define LINF 9999999999999999
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
using namespace std;

int n;
char a,b;
int aa,bb;

int main(){
	cin >> a >> b;
	cin >> n;
	if(a == 118)aa=1;
	if(a == 60)aa=2;
	if(a == 94)aa=3;
	if(a == 62)aa=4;
	if(b == 118)bb=1;
	if(b == 60)bb=2;
	if(b == 94)bb=3;
	if(b == 62)bb=4;
	n %= 4;
	if((aa+n)%4==bb%4&&(bb+n)%4==aa%4) cout << "undefined" << endl;
	else if((aa+n)%4==bb%4)cout << "cw" << endl;
	else if((bb+n)%4==aa%4)cout << "ccw" << endl;
	return 0;
}