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

const int N = 300005;
int x[N], y[N];

int getDist(int a, int b, int c){
	return  2 * (max(x[a], max(x[b], x[c])) - 
		min(x[a], min(x[b], x[c])) + max(y[a], max(y[b], y[c])) - min(y[a], min(y[b], y[c])));
}

int main(){
	vector<int> indices;
	int mxX = -1e9, mnX = 1e9, mxY = -1e9, mnY = 1e9;
	int ind1, ind2, ind3, ind4;
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(x[i]);
		sd(y[i]);
		if(mnX > x[i]){
			mnX = x[i];
			ind1 = i;
		}

		if(mnY > y[i]){
			mnY = y[i];
			ind3 = i;
		}

		if(mxX < x[i]){
			mxX = x[i];
			ind2 = i;
		}

		if(mxY < y[i]){
			mxY = y[i];
			ind4 = i;
		}
	}
	vector<int> V = {ind1, ind2, ind3, ind4};
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++){
				if(i != V[j] && i != V[k] && V[j] != V[k]){
					ans = max(ans, getDist(i, V[j], V[k]));
				}
			}
	}
	printf("%d ", ans);
	for(int i = 4; i <= n; i++) printf("%d ", 2 * (mxX - mnX + mxY - mnY));
}