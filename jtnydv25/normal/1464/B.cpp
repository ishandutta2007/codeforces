#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

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

template<class T>
ostream& operator <<(ostream& os,const set<T>& v){
	os<<"{";
	for(auto it = v.begin(); it != v.end(); it++){
		if(it != v.begin())os<<", ";
		os<<*it;
	}
	os<<"}";
	return os;
}

template<class T, class V>
ostream& operator <<(ostream& os,const map<T, V>& v){
	os<<"{";
	for(auto it = v.begin(); it != v.end(); it++){
		if(it != v.begin())os<<", ";
		os<<*it;
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	string s;
	ll x, y;
	cin >> s >> x >> y;
	int n = s.length();
	if(x > y){
		swap(x, y);
		for(int i = 0; i < n; i++) if(s[i] != '?'){
			s[i] = s[i] == '0' ? '1' : '0';
		}
	}
	vector<int> pos;
	y -= x;
	ll zeroes = count(all(s), '0');
	ll ones = count(all(s), '1');
	int Q = n - ones - zeroes;
	int a = 0, b = 0;
	vector<ll> suff(n + 1);
	vector<int> Z(n + 1);

	for(int i = n - 1; i >= 0; i--){
		suff[i] = suff[i + 1];
		char c = s[i];
		if(c == '1' || c == '?') suff[i] += a;
		else a++;
		Z[i] = a;
	}
	ll ans = (ones + Q) * zeroes * x + y * suff[0];
	int q = 0;
	ll num = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '?'){
			q++;
			num += b;
			ans = min(ans, (ones + Q - q) * (zeroes + q) * x + y * (num + suff[i + 1] + b * 1LL * Z[i + 1]));
		} else if(s[i] == '1'){
			b++;
		} else{
			num += b;
		}
	}
	cout << ans << endl;
}