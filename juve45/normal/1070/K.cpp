#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define dbg_v(v,n) {cerr<<#v<<" = [";for(int III=0;III<=n;III++)cerr<<v[III]<<(III!=n?",":"]\n");}
#define ll long long
#define ld long double
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define Nmax 100005
using namespace std;

int n,k,s,nr,v[Nmax];
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> v[i];
		s += v[i];
	}
	if (s % k != 0){
		cout << "No\n";
		return 0;
	}
	s /= k;
	int crt = 0;
	for (int i=1;i<=n;){
		while (crt + v[i] <= s && i <= n) crt += v[i], i++,nr++;
		if (crt != s){
			cout << "No\n";
			return 0;
		}
		ans.push_back(nr);
		crt = 0;
		nr = 0;
	}
	cout << "Yes\n";
	for (auto it : ans) cout << it << ' ';
    return 0;
}