#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

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

const int N = 305;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a[N][N], b[N][N];
int main(){
	int t; sd(t);
	while(t--){
		int n, m;
		sd(n); sd(m);
		bool ok = true;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			sd(a[i][j]);
			int num = 0;
			for(int k = 0; k < 4; k++){
					int _i = i + dx[k], _j = j + dy[k];
					if(min(_i, _j) >= 0 && _i < n && _j < m){
						num++;
					}
			}
			if(a[i][j] > num){
				ok = false;
			}
			a[i][j] = num;
		}

		if(!ok){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}