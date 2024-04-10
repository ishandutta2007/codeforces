#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int N = 1005;
typedef pair<int,int> pii;

int n, x[N], y[N], a[N], b[N];
set<pii> s;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		s.insert({a[i], b[i]});
	}
	for(int i=1;i<=n;i++) {
		int A = x[1] + a[i], B = y[1] + b[i];
		bool F = false;
		for(int j=2;j<=n;j++) {
			if(s.find({A-x[j], B-y[j]}) == s.end()) {
				F = true;
				break;
			}
		}
		if(!F) {
			printf("%d %d\n", A, B);
			return 0;
		}
	}
}