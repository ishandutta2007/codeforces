#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;++i)

int main(){
	int a , b , c , d;
	cin >> a >> b >> c >> d;
	cout << ((( a^b ) & ( c|d )) ^ (( b&c ) | ( a^d ))) << endl;
	return 0;
}