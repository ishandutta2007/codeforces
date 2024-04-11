#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;
#define sz(v) ((int)(v).size())

int n, k, a[MAXN];
int low[MAXN];

int main(){
	for(int i=2; i<MAXN; i++){
		for(int j=i; j<MAXN; j+=i){
			if(!low[j]) low[j] = i;
		}
	}
	scanf("%d",&n);
	scanf("%d",&k);
	map<vector<pi>, int> mp;
	lint ret = 0;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		vector<pi> v, w;
		for(int j=a[i]; j>1; ){
			int l = low[j];
			int c = 0;
			while(j % l == 0){
				j /= l;
				c++;
			}
			c %= k;
			if(c == 0) continue;
			v.emplace_back(l, c);
			w.emplace_back(l, k - c);
		}
		ret += mp[w];
		mp[v]++;
	}
	cout << ret << endl;
}