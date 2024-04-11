#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int mod = 998244353;

int n, b[MAXN];

int query2(int l, int r){
	if(rand() & 1){
		for(int i=1; i<=r; i++) b[i] ^= 1;
		return count(b + 1, b + n + 1, 1);
	}
	else{
		for(int i=l; i<=n; i++) b[i] ^= 1;
		return count(b + 1, b + n + 1, 1);
	}
}
int query(int l, int r){
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x; scanf("%d",&x);
	assert(x != -1);
	return x;
}

int m, a[MAXN];

void IHateRandomInteractiveProblem(){
	printf("! ");
	for(int i=1; i<=n; i++) printf("%d",a[i]);
	fflush(stdout);
	exit(0);
}

int main(){
	scanf("%d %d",&n,&m);
	srand(time(0));
	if(m == 0){
		IHateRandomInteractiveProblem();
	}
	if(m == n){
		fill(a + 1, a + n + 1, 1);
		IHateRandomInteractiveProblem();
	}
	int S = 0;
	for(int i=2; i<=n; i++){
		// assume a_{i-1} = 0
		int evenNorm = m;
		int evenFucked = (i - 1 - S) + (m - S);
		int oddNorm = n - m;
		int oddFucked = S + (n - i + 1 - (m - S));
		int vote0 = 0;
		int vote1 = 0;
		for(int j=1; j<=24; j++){
			int R = query(i, n);
			if(j % 2 == 0){
				if(evenNorm == evenFucked){
					if(R == evenNorm) vote0++;
					else{
						vote1 = 1234567;
					}
				}
				else{
					if(R == evenFucked){
						vote0 = 1234567;
					}
					else vote1++;
				}
			}
			else{
				if(oddNorm == oddFucked){
					if(R == oddNorm) vote0++;
					else{
						vote1 = 1234567;
					}
				}
				else{
					if(R == oddFucked){
						vote0 = 1234567;
					}
					else vote1++;
				}
			}
			if(j % 2 == 0 && max(vote0, vote1) > 1e6) break;
		}
		if(vote0 < vote1){
			a[i - 1] = 1;
			S++;
		}
		{
			int evenNorm = m;
			for(int j=1; ; j++){
				int R = query(i, n);
				if(j % 2 == 0){
					if(R == evenNorm) break;
				}
			}
		}
	}
	if(S != m) a[n] = 1;
	IHateRandomInteractiveProblem();
}