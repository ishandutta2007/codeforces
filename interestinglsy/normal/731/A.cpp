#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define INF (1e+8)
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

string s;
int len;
int main(){
	cin >> s;
	len = s.length();
	char lastc = 'a';
	int ans = 0;
	for( int i = 0; i < len; i++ ){
		ans += min( abs(s[i]-lastc) , 26-abs(s[i]-lastc) );
		lastc = s[i];
	}
	cout << ans << endl;
	return 0;
}