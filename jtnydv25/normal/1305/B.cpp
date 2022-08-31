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
char s[10005];
int main(){
	int t = 1; 
	// sd(t);
	while(t--){
		scanf("%s", s);
		int n = strlen(s);
		vector<vector<int>> pos(2);
		for(int i = 0; i < n; i++){
			pos[s[i] == '('].push_back(i);
		}
		reverse(all(pos[0]));
		int num_l = 0, num_r = pos[0].size();
		if(num_r == 0){
			printf("0\n");
			continue;
		}
		vector<int> A, B;
		B = pos[0];
		int ans;
		vector<int> positions;
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				num_l++;
				A.push_back(i);
			}
			else{
				num_r--;
				B.pop_back();
			}
			if(num_l == num_r){
				if(num_l==0){
					ans = 0;
				} else{
					ans = 1;
				}
				break;
			}
		}
		printf("%d\n", ans);
		if(ans == 1){
			sort(all(B));
			printf("%d\n", sz(A) + sz(B));
			for(auto it : A) printf("%d ", it + 1);
			for(auto it : B) printf("%d ", it + 1);
			printf("\n");
		}
	}
}