#include <bits/stdc++.h>
using namespace std;
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
const int N = 200005;
int a[N];
int pref[N];
int p1[N], p2[N];

int main(){
	int h;
	scanf("%d", &h);
	for(int i = 0; i <= h; i++) scanf("%d", a + i), pref[i] = pref[i - 1] + a[i];
	int i = 0;
	int lftmost = 0, curr = 1;
	while(i <= h && (a[i] <= 1 || a[i + 1] <= 1)){
		int lftmost2 = curr;
		// trace(lftmost);
		for(int j = 0; j < a[i]; j++) p1[curr] = p2[curr] = lftmost, curr++;
		i++;
		lftmost = lftmost2;
	}
	if(i >= h){
		printf("perfect");
		return 0;
	}
	if(pref[h] - pref[i] <= 1){
		printf("perfect");
		return 0;
	}
	printf("ambiguous\n");
	int n = pref[h];
	int st = curr;
	int nxtst = st + a[i];
	for(int j = i; j <= h; j++){
		int lftmost2 = curr;
		for(int done = 0; done < a[j]; done++){
			p1[curr] = p2[curr] = lftmost;
			curr++;
		}
		lftmost = lftmost2;
	}
	p2[nxtst] = st + 1;
	for(int i = 1; i <= n; i++) printf("%d ", p1[i]);
	printf("\n");
	for(int i = 1; i <= n; i++) printf("%d ", p2[i]);
	return 0;
}