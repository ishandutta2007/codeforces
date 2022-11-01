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
ull a,b,t;
int main(){
	//freopen("C.txt","r",stdin);
	scanf("%d",&n);
	for( int ni = 1 ; ni <= n ; ni++ ){
		scanf("%lld %lld",&a,&b);
		t = a*b;
		long double ret = pow( double(t) , double(1.0/3.0) );
		//cout << double(t) << " " << ret << endl;
		ll o = floor( ret+0.5 );
		//cout << o << endl;
		if( o <= 0  ||  ( o*o*o ) != t ){
			printf("No\n");
			continue;
		}
		if( (a+b) % o == 0 ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}