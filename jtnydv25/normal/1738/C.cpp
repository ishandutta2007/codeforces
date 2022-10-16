#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

const int N = 105;
int winner[N][N][2][2];


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	winner[0][0][0][1] = winner[0][0][1][1] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i + j == 0) continue;
			for(int k = 0; k < 2; k++){
				for(int s = 0; s < 2; s++){
					int w = k ^ 1;
					if(i > 0 && winner[i - 1][j][k ^ 1][s] == k) w = k;
					if(j > 0 && winner[i][j - 1][k ^ 1][s ^ (k==0)] == k) w = k;
					winner[i][j][k][s] = w;
				}
			}
		}
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		vector<int> u(2);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			u[abs(a[i]) % 2]++;
		}
		cout << (winner[u[0]][u[1]][0][0] == 0 ? "Alice" : "Bob") << endl;
	}
}