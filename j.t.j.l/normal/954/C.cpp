#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	vector<int>f;
	for (int i = 1; i < n; i++)
		if (abs(a[i] - a[i+1]) != 1)
			f.push_back(abs(a[i] - a[i+1]));
	sort(f.begin(), f.end());
	f.resize(unique(f.begin(), f.end()) - f.begin());
	if (f.size() > 1){
		puts("NO");
		return ;
	}
	else if (f.size() == 0){
		puts("YES");
		cout << 1000000000 << ' ' << 1 << endl;
	}
	else {
		if (f[0] == 0)
			puts("NO");
		else{
			//check()!!!;
			int flag = 1;
			for (int i = 1; i < n; i++)
				if (abs(a[i] - a[i+1]) == 1)
					if (min(a[i], a[i+1]) % f[0] == 0)
						flag = 0;
			if (flag) cout << "YES" << endl << 1000000000 << ' ' << f[0] << endl;
			else cout << "NO" << endl;
		}
	}
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}