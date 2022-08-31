#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

int pa[5005], pb[5005];
int main(){
	string s;
	cin >> s;
	int curr = 0;
	int n = s.length();
	for(int i = 1; i <= n; i++){
		pa[i] = pa[i - 1] + (s[i - 1] == 'a');
		pb[i] = pb[i - 1] + (s[i - 1] == 'b');
	}
	pb[n + 1] = pb[n];
	pa[n + 1] = pa[n];
	int mx = 1;
	for(int i = 0; i <= n; i++){
		for(int j = i + 1; j <= n + 1; j++){
			int na1 = pa[i], na2 = pa[n] - pa[j - 1], nb = pb[j - 1] - pb[i];
			mx = max(mx, na1 + na2 + nb);
		}
	}
	cout << mx;
}