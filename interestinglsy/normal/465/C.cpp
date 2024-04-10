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
#define MAXN 1100

int n,p;
char inp[MAXN];
/*
Exitcode	Status
0			ok
1			same
*/
char s[MAXN];
#define OK(x) ((x-2 < 0  ||  (x-2>=0&&s[x-2] != s[x]))  &&  (x-1 < 0  ||  (x-1>=0&&s[x-1] != s[x])))
bool plus1( int pos ){
	strcpy( s , inp );
	//cout << "---------------New---------------\n";
	//cout << "[New]  " << s << " " << pos << endl;
	s[pos]++;
	while( s[pos] < 'a'+p  &&  !OK(pos) ) s[pos]++;
	if( s[pos] == 'a'+p ){
		//cout << "Exitcode 1\n";
		return 1;
	}
	while( pos+1 < n ){
		pos++;
		//cout << "[POS]: " << pos << endl;
		s[pos] = 'a';
		while( s[pos] < 'a'+p  &&  !OK(pos) ) s[pos]++;
		if( s[pos] == 'a'+p ){
			return 1;
		}
	}
	return 0;
}

int main(){
	//freopen("C.txt","r",stdin);
	
	scanf("%d %d",&n,&p);
	scanf("%s",&inp);
	
	for( int i = n-1 ; i >= 0 ; i-- ){
		int status = plus1( i );
		if( !status ){
			printf("%s\n",s);
			//cout << i << endl;
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}