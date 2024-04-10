#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

string s1 = "RGBYW", s2 = "12345";

map<char, int > mp1, mp2;
int F[105], G[105];
int main(){
	int n = 1;
	cin >> n;
	for(int i = 0; i < 5; i++) mp1[s1[i]] = i, mp2[s2[i]] = i;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		F[i] = mp1[s[0]];
		G[i] = mp2[s[1]];
		// cnt[F[i]][G[i]]++;
	}
	int ans = 10;
	for(int mask1 = 0; mask1 < 32; mask1++){
		for(int mask2 = 0; mask2 < 32; mask2++){
			bool valid = 1;
			for(int i = 0; i < n; i++){
				for(int j = i + 1; j < n; j++){
					if(!(F[i] == F[j] && G[i] == G[j])){
						// cerr << i << " " << j << endl;
						int x = F[i] == F[j] ? 0 : abs(((mask1 >> F[i]) & 1) + ((mask1 >> F[j]) & 1));
						int y = G[i] == G[j] ? 0 : abs(((mask2 >> G[i]) & 1) + ((mask2 >> G[j]) & 1));
						if(x + y == 0){
							valid = 0;
						}
					}
				}
			}
			if(valid) ans = min(ans, __builtin_popcount(mask1) + __builtin_popcount(mask2));
		}
	}
	cout << ans;
}