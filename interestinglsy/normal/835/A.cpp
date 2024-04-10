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
#include <bitset>
#define pb push_back
#define mp make_pair
#define INF (1e9)
#define LINF (1e18)
#define uint unsigned int
#define msn(_data,_val) memset(_data,_val,sizeof(_data))
#define ms(_data) memset(_data,0,sizeof(_data))
#define NONE -1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define sint short int
#define usint unsigned sint
#define lb lower_bound
#define ub upper_bound
#define out cout << 
#define print(_num) printf("%d\n",_num);
#define ln printf("\n");
#define read(_num) scanf("%d",&_num);
using namespace std;

int s , v1 , v2 , t1 , t2;

int main(){
	scanf("%d %d %d %d %d",&s,&v1,&v2,&t1,&t2);
	if( s*v1+2*t1 < s*v2+2*t2 ) out "First";
	if( s*v1+2*t1 > s*v2+2*t2 ) out "Second";
	if( s*v1+2*t1 == s*v2+2*t2 ) out "Friendship";
	ln;
	return 0;
}