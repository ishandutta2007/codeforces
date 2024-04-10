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
	//freopen("B.txt","r",stdin);
	
	scanf("%d",&n);
	int last1 = 0;
	int ans = 0;
	for( int i = 1 ; i <= n; i++ ){
		int x;
		scanf("%d",&x);
		if( last1 == 0  &&  x == 1){
			last1 = i;
			ans++;
		}else
			if( x == 1 ){
				ans += min( i - last1 , 2 );
				last1 = i;
			}
	}
	
	printf("%d\n",ans);
	
	return 0;
}