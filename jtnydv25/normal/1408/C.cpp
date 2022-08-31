#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
const double EPS = 1e-9;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int T; cin >> T;
	while(T--){
		int n, l;
		cin >> n >> l;
		vector<int> a(n + 2);
		a[0] = 0;
		a[n + 1] = l;
		for(int i = 1; i <= n; i++) cin >> a[i];
		double pos1 = 0, pos2 = l;
		int s1 = 1, s2 = 1;
		int ptr1 = 1, ptr2 = n;
		double t = 0;
		while(true){
			assert(pos1 <= pos2);
			double meet_time = (pos2 - pos1) / (double) (s1 + s2);
			double t1 = (a[ptr1] - pos1) / s1;
			double t2 = (pos2 - a[ptr2]) / s2;
			// trace(t1, t2, meet_time, ptr1, ptr2);
			if(meet_time <= t1 + EPS && meet_time <= t2 + EPS){
				cout << setprecision(15) << fixed << t + (pos2 - pos1) / (s1 + s2) << endl;
				break;
			}
			if(t1 <= t2){
				pos1 += t1 * s1;
				pos2 -= t1 * s2;
				ptr1++;
				s1++;
				t += t1;
			} else{
				pos1 += t2 * s1;
				pos2 -= t2 * s2;
				ptr2--;
				s2++;
				t += t2;
			}
		}
	}
}