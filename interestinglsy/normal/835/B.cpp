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
#define in cin >> 
#define print(_num) printf("%d\n",_num);
#define ln printf("\n");
#define read(_num) scanf("%d",&_num);
using namespace std;

int k , len ;
string n;
priority_queue<int> pq;

int main(){
	//freopen("B.txt","r",stdin);
	in k; in n; len = n.length();
	ll nsum = 0;
	for( int i = 0 ; i < len ; i++ ){
		int cha = 10 - (n[i]-'0') - 1;
		pq.push(cha);
		nsum += (n[i]-'0');
	}
	ll need = k - nsum;
	if( need <= 0 ){
		out 0;
		return 0;
	}
	int ans = 0;
	while( 1 ){
		ans++;
		need -= pq.top();
		pq.pop();
		if( need <= 0 ){
			out ans;
			return 0;
		}
	}
	return 0;
}