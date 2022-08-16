#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                pi[i] = k;
    return pi;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		vector<int> f(26);
		int n = s.length();
		string ss = "";
		for(int i = 0; i < n; i++) f[s[i] - 'a']++;
		int mn = n + 1, c = 0;
		int minc = 26;
		for(int i = 0; i < 26; i++){
			if(f[i] != 0 && f[i] < mn){
				mn = f[i];
				c = i;
			}
			if(f[i] != 0 && minc == 26) minc = i;
		}
		if(mn != 1)c = minc;
		ss += ('a' + c);
		f[c]--;
		int lst = c;
		int prohibited = -1;
		if(mn == 1 || f[c] + 1 == n){
			for(int i = 0; i < 26; i++){
				for(int j = 0; j < f[i]; j++) ss += ('a' + i);
			}
		} else{
			for(int i = 1; i < n; i++){
				for(int j = 0; j < 26; j++) if(f[j] && (lst != c || j != prohibited)){
					f[j]--;
					int old = prohibited;
					if(i == 1) prohibited = j;
					bool ok = true;
					if(f[c] || (j == c && i != n - 1)){
						int num = f[c] - 1;
						if(j == c && i != n - 1) num = max(1, f[c]);
						int sum = 0;
						for(int k = 0; k < 26; k++) if(prohibited != k) sum += f[k];
						if(sum < num) ok = false;
						// if(i==2) trace(prohibited, j, c, f[c]);
						// if(i==3)trace(i, j, sum, num);
						if(f[prohibited] > 0 && prohibited != -1 && j == c){
							if(prohibited == c){

							} else{
								if(f[c] + f[prohibited] == n - 1 - i) ok = false;
							}
						}
					}
					// if(i==3) trace(j, ok);
					if(!ok){
						f[j]++;
						prohibited = old;
					} else{
						lst = j;
						ss += ('a' + lst);
						// trace(i, lst);
						break;
					}
				}
			}
		}
		
		cout << ss << endl;
	}
}