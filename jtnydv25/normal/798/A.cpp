#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
bool is_pal(string s){
	string t = s;
	reverse(all(t));
	return t == s;
}
int main(){
	int t = 1, n;
	// sd(t);
	while(t--){
		string s;
		cin >> s;
		for(int i =0; i < s.length(); i++){
			for(int l = 0; l < 26; l++){
				string t = s;
				if(t[i] - 'a' == l) continue;
				t[i] = (char) ('a' + l);
				if(is_pal(t)){
					cout << "YES"; return 0;
				}
			}
		}
		cout << "NO";
	}
	return 0;
}