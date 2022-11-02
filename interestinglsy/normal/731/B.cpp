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
#define MAXN 200100

int n;

int main(){
//	freopen("B.txt","r",stdin);
	
	scanf("%d",&n);
	
	bool faild = 0;
	bool more = 0;
	for( int i = 1; i <= n  &&  !faild ; i++ ){
		int x;
		scanf("%d",&x);
		if( x == 0  &&  more ) faild = 1;
		if( more ) x--;
		more = 0;
		if( x % 2 == 0 ) continue;
		else more = 1;
	}
	if( more ) faild = 1;
	
	if( !faild ) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}