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

const int MAX = 1e6 - 100;
const int N = 2005;
int a[N];
ll find_answer(){

}

int main(){
	int k; sd(k);
	if(k <= MAX){
		printf("2\n");
		printf("%d %d\n", -1, k + 2);
		return 0;
	}

	int minS = max(1, k / 2000);
	for(int s = minS; ; s++){
		int num_mul = (k + 1500) / s - (k - 1) / s;
		if(num_mul > 0){
			int _s = s;
			int _l = s * ((k - 1) / s + 1) - k;
			int l = (k + _l) / s + _l;
			if(l <= 2000 && MAX * (ll) _l >= s + 1){
				printf("%d\n", l);
				for(int i = 1; i <= l - _l - 1; i++){
					a[i] = 0;
					printf("0 ");
				}
				a[l - _l] = -1;
				printf("-1 ");
				s++;
				for(int i = l - _l + 1; i <= l; i++){
					int num = (s >= MAX) ? MAX : s;
					s -= num;
					a[i] = num;
				}
				reverse(a + l - _l + 1, a + l + 1);
				for(int i = l - _l + 1; i <= l; i++) printf("%d ", a[i]);
				printf("\n");
				return 0;
			}
		}
	}
}