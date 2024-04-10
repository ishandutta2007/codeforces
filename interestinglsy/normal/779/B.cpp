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
#define pb push_back
#define mp make_pair
#define INF 9999999
#define LINF 9999999999999999
#define SINF "%"
#define uint unsigned int
#define msn(a,v) memset(a,v,sizeof(a))
#define ms(a) msn(a,0)
#define NONE -1
#define allowxout 1
#define ll long long
#define ull unsigned ll
#define uchar unsigned char
#define xout(a) if(allowxout) cout << "[X] " << a << " "
#define xout2(a,b) if(allowxout) cout << "[X2] " << a << " " << b << " "
#define xoutln(a) if(allowxout) cout << "[X] " << a << endl
#define xout2ln(a,b) if(allowxout) cout << "[X2] " << a << " " << b << endl
using namespace std;

ll n;
string s;
int len;
int k;

ll p10(int x){
	if(x == 0) return 1;
	if(x == 1) return 10;
	if(x == 2) return 100;
	if(x == 3) return 1000;
	if(x == 4) return 10000;
	if(x == 5) return 100000;
	if(x == 6) return 1000000;
	if(x == 7) return 10000000;
	if(x == 8) return 100000000;
	if(x == 9) return 1000000000;
	return 23333;
}


int main(){
//	freopen("B.txt","r",stdin);
	
	while(cin >> s >> k){
		len = s.length();
		int zero = 0;
		int ans = 0;
		for(int i = len-1;i >= 0;i--){
			if(s[i] == '0') zero++;
			else ans++;
			if(zero == k) break;
		}
		if(zero < k){
			cout << len-1 << endl;
		}else{
			cout << ans << endl;
		}
	}
	return 0;
}