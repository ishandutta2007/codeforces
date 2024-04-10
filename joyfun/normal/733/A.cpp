#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 100005;
char str[N];

bool judge(char c) {
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') return true;
	return false;
}

int main(){
	scanf("%s", str + 1);
	int len = strlen(str + 1);
	str[0] = 'A'; str[++len] = 'A';
	int ans = 0;
	for (int i = 0; i <= len; i++) {
		if (!judge(str[i])) continue;
		for (int j = i + 1; j <= len; j++) {
			if (judge(str[j])) {
				ans = max(ans, j - i);
				break;
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}