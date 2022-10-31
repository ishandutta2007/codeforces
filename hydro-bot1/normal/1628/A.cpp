// Hydro submission #6225a7eb6fc4a10167d6bf86@1646634987431
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f


using namespace std;

typedef long long ll;

const int N = 201000, MAXN = 200100;
typedef pair<ll, ll> PLL;
typedef pair<int, int> PII;

int a[200100];
int p[200100], endd[200100]; 


struct MEX {
	int vis[MAXN];
	vector<int> num;
	int k = 0;
	void add(int a){
		num.push_back(a);
		vis[a]++;
	}
	int mex(){
		while(vis[k]) k++;
		return k;
	}
	void clear(){
		k = 0;
		for(auto c : num){
			vis[c] = 0;			
		}
		num.clear();
	   	memset(vis, 0, sizeof(vis));
	}
};


void slove() {
	int t; cin >> t;
	while(t--){
		memset(endd, 0, sizeof(endd));
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		vector<int> ans;
		int n; cin >> n;
		MEX pre, last;
		last.clear(); pre.clear();
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = n; i >= 1; i--){
			last.add(a[i]);
			endd[i] = last.mex();
		}
		int key = endd[1];
		for(int i = 1; i <= n; i++){
			pre.add(a[i]);
			if(pre.mex() == key) {
				ans.push_back(pre.mex());
				pre.clear();
				key = endd[i+1];
			}
		}
		cout << ans.size() << '\n';
		for(auto c : ans){
			cout << c << ' ';
		}
		cout << '\n';
	}
}




int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    slove();
    
}