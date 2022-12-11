#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)
 
typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
 
const int N = 110;
 
char s[N];
 
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), cnt = 0, cnt1 = 0;
	for(int i = n; i >= 1; i -= 2) {
		if(i == 1) {
			cnt1 = 0;
			for(int j = i + 1; j <= n; j ++) if(s[j] == '1') cnt1 ++;
		}
		if(i != 1 || cnt1) cnt ++;
	}
	printf("%d\n", cnt);
	return 0;
}