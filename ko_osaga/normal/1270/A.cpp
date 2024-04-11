#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
const int MAXN = 2505;
using pi = pair<int, int>;
using lint = long long;

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n, k1, k2; 
		scanf("%d %d %d",&n,&k1,&k2);
		string ans = "NO";
		for(int i=0; i<k1; i++){
			int x; scanf("%d",&x);
			if(x == n) ans = "YES";
		}
		for(int i=0; i<k2; i++){
			scanf("%*d");
		}
		puts(ans.c_str());
	}
}