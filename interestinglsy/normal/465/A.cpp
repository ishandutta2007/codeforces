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

int n;

int main(){
//	freopen("A.txt","r",stdin);
	scanf("%d",&n);
	char x;
	scanf("%c",&x);
	for( int i = 1;i <= n;i++){
		scanf("%c",&x);
		if(x == '0'){
			cout << i << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}