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

int firstapp[28];
int lastapp[28];
int n,k;
string s;
int main(){
	//freopen("B.txt","r",stdin);
	
	msn(firstapp,-1);
	cin >> n >> k;
	cin >> s;
	for( int i = 0 ; i < n ; i++ ){
		int let = s[i]-'A';
		if( firstapp[let] == -1 ) firstapp[let] = i;
		lastapp[let] = i;
	}
	
	int open = 0;
	for( int i = 0 ; i < n; i++ ){
		int let = s[i]-'A';
		if( firstapp[let] == i ) open++;
		//cout << open << endl;
		if( open > k ){
			cout << "YES" << endl;
			return 0;
		}
		if( lastapp[let] == i ) open--;
	}
	
	cout << "NO" << endl;
	
	return 0;
}