#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 1e5 + 5;
string S[N], C[N];
map<ll, int> Hind;
const ll  mod = 10000000000000061;
const int base = 31;
inline int val(char c){
	return tolower(c);
}
ll Hash(string s){
	ll ret = 0;
	for(int i = 0; i < s.length(); i++) ret = (ret * base + val(s[i]));
	return ret;	
}
int dp[N];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	string t;
	cin >> n >> t >> m;
	for(int i = 1; i <= m; i++){
		cin >> S[i];
		Hind[Hash(S[i])] = i;
	}
	for(int i = 0; i < n; i++) dp[i] = -1;
	for(int i = 0; i < n; i++){
		ll H = 0;
		for(int k = 1; k <= i + 1 && k <= 1000; k++){
			H = (H * base + val(t[i - k + 1]));
			if(k == i + 1){
				dp[i] = Hind.count(H) ? Hind[H] : -1;
				break;
			}
			if(dp[i - k] == -1) continue;
			if(Hind.count(H)){ dp[i] = Hind[H]; break;}
		}
	}
	vector<int> vec; n--;
	while(n >= 0){
		vec.pb(dp[n]);
		n -= S[dp[n]].length();
	}
	reverse(vec.begin(), vec.end());
	for(int i =0; i < vec.size(); i++) cout << S[vec[i]] << " ";
}