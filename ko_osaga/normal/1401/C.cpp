#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> v(n);
		for(auto &i : v) scanf("%d",&i);
		int mv = *min_element(all(v));
		vector<int> w;
		for(int i=0; i<n; i++){
			if(v[i] % mv == 0) w.push_back(v[i]);
		}
		sort(all(w), [&](const int &a, const int &b){
			return a < b;
		});
		for(int i=n-1; i>=0; i--){
			if(v[i] % mv == 0){
				v[i] = w.back();
				w.pop_back();
			}
		}
		puts(is_sorted(all(v)) ? "YES" : "NO");
	}
}