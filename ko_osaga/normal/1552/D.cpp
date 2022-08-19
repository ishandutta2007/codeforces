#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int a[22];

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i] = abs(a[i]);
		}
		string ans = "NO";
		for(int i = 0; i < (1<<n); i++){
			for(int j = 1; j < (1<<n); j++){
				int sum = 0;
				for(int k = 0; k < n; k++){
					if((j >> k) & 1){
						int val = a[k];
						if((i >> k) & 1) val *= -1;
						sum += val;
					}
				}
				if(sum == 0) ans = "YES";
			}
		}
		cout << ans << endl;
	}
}