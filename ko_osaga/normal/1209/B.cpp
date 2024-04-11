#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
const int MAXN = 200005;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<lint, lint>;

int cnt[696969];
string s;

int main(){
	int n;
	cin >> n;
	cin >> s;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		int curOn = (s[i] == '1' ? 1 : -1);
		cnt[0] += max(curOn, 0);
		for(int j=b; j<696969; j+=a){
			curOn *= -1;
			cnt[j] += curOn;
		}
	}
	for(int i=1; i<696969; i++) cnt[i] += cnt[i-1];
	cout << *max_element(cnt, cnt + 696969) << endl;
}