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

const int N = 1e5 + 10;

int n, tag[100];
char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i ++) {
		if(s[i] == 'L') {
			for(int j = 0; j < 10; j ++) {
				if(!tag[j]) {
					tag[j] = 1; break ;
				}
			}
		}
		else if(s[i] == 'R') {
			for(int j = 9; ~ j; j --) {
				if(!tag[j]) {
					tag[j] = 1; break ;
				}
			}
		}
		else {
			tag[s[i] - '0'] = 0;
		}
	}
	for(int i = 0; i < 10; i ++) printf("%d", tag[i]);
	return 0;
}