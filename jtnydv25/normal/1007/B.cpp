#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 100005;
int ndiv[N];
int a[3];
int arr[8];

vector<int> perm[6];
inline int f(){
	for(int j = 0; j < (1 << 3); j++){
		arr[j] = 0;
		for(int k = 0; k < 3; k++) if(j >> k & 1) arr[j] = __gcd(arr[j], a[k]);
		arr[j] = ndiv[arr[j]];

	}
	int all = arr[7];
	int two_same = 0;
	for(int j = 1; j < (1 << 3); j++){
		int cnt = 0;
		int mask_d2 = j, mask_d1 = 0;
		for(int k = 0; k < 3; k++){
			if(j >> k & 1){
				cnt++;
				mask_d1 |= (7 ^ (1 << k));
			}
		}
		if(cnt & 1)two_same += arr[mask_d1] * arr[mask_d2];
		else two_same -= arr[mask_d1] * arr[mask_d2];
	}
	two_same -= all;
	int diff = 0;
	for(int i = 1; i < (1 << 6); i++){
		int msk[3] = {0, 0, 0};
		int cnt = 0;
		for(int k = 0; k < 6; k++){
			if(i >> k & 1){
				for(int t = 0; t < 3; t++) msk[t] |= (1 << perm[k][t]);
				cnt++;
			}
		}
		int val = arr[msk[0]] * arr[msk[1]] * arr[msk[2]];
		if(cnt & 1) diff += val;
		else diff -= val;
	}
	diff -= all + 3 * two_same;
	assert(diff % 6 == 0);
	diff  /= 6;
	return diff + two_same + all;
}

int main(){
	for(int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			ndiv[j]++;

	int t; sd(t);
	perm[0] = {0, 1, 2};
	perm[1] = {0, 2, 1};
	perm[2] = {1, 0, 2};
	perm[3] = {1, 2, 0};
	perm[4] = {2, 0, 1};
	perm[5] = {2, 1, 0};
	while(t--){
		sd(a[0]); sd(a[1]); sd(a[2]);
		printf("%d\n", f());
	}
}