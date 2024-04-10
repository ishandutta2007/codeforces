#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
const int N = 300005;

int n, b[N];
pii a[N];

vector<pii> s;
vector<pair<pii, int> > ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i].X);
		a[i].Y = i;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
	}
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
    for(int i=n;i>=1;i--) {
		if(a[i].X > b[i]) {
			s.push_back({a[i].X - b[i], a[i].Y});
		}
		else {
			int T = b[i] - a[i].X;
			while(!s.empty() && T > 0) {
				int A, B;
				tie(A, B) = s.back();
				s.pop_back();
				if(A > T) {
					ans.push_back({{a[i].Y, B}, T});
					s.push_back({A-T, B});
					T = 0;
				}
				else {
					ans.push_back({{a[i].Y, B}, A});
					T -= A;
				}
			}
			if(T > 0) {
				puts("NO");
				return 0;
			}
		}
    }
    if(s.size() > 0) {
		puts("NO");
		return 0;
    }
    puts("YES");
    printf("%d\n", ans.size());
    for(auto &T : ans) {
		printf("%d %d %d\n", T.X.X, T.X.Y, T.Y);
    }
}