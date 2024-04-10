#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + N;
const int LOG = 18;
const int OFF = (1 << LOG);

int prost[M], dp[M];

void precompute(){
	dp[1] = 1;
	for(int i = 2;i < M;i++){
		if(prost[i]) continue;
		dp[i]++;
		if(i - 10 < M / i  && i * i < M)
			dp[i * i]--;
		for(int j = 2 * i;j < M;j += i)
			prost[j] = 1;
		
	}
	for(int i = 1;i < M;i++)
		dp[i] += dp[i - 1];
}

int main(){
	precompute();
	int T; scanf("%d", &T);
	for(;T--;){
		int q; scanf("%d", &q);
		printf("%d\n", dp[q]);
	}
	return 0;
}