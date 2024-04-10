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

int a[MAXN], vis[MAXN];
map<int, int>mp;
int f[2][MAXN];
int umi[MAXN];

int calc(int nico){
	for(int i = 1; i <= n; i++){
		f[0][i] = -1;
		umi[i] = 0;
	}
	f[0][0] = 0;
	int m = 0;
	for(auto x : mp){
		umi[x.first] = x.second;
	}
	//cout<<nico<<endl;
	//for(auto x : mp){
	for(int i = n; i >= 1; i--){
		if (umi[i] == 0) continue;
		if (i % 2 == 0 && umi[i>>1] > 0){
			umi[i>>1] += umi[i]*2;
			continue;
		}
		m = 1-m;
		int v = i, ct = umi[i];
	//	cout<<v<<' '<<ct<<endl;
		f[m][0] = 0;
		for(int j = 1; j <= n; j++){
			if (f[1-m][j] != -1)
				f[m][j] = 0;
			else{
				if (j >= v){
					if (f[m][j-v] < ct && f[m][j-v] != -1)
						f[m][j] = f[m][j-v] + 1;	
					else
						f[m][j] = -1;
				}
				else{
					f[m][j] = -1;
				}
			}
		}
	//	cout<<f[m][nico]<<endl;
	}
	return (f[m][nico] == -1) ? 0 : 1;
}

void solve(int casi){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		vis[i] = 0;
	}
	vector<int> b;
	for(int i = 1; i <= n; i++)
		if (!vis[i]){
			int fg = 0;
			for(int j = i; !fg || j != i; fg++, j = a[j])
				vis[j] = 1;
			b.push_back(fg);
			mp[fg]++;
		}
	sort(b.begin(), b.end());
	int p = m + 1 - calc(m);
	int q = 0;
	if (m <= b.size()) q = 2 * m;
	else{
		for(int i = 0; i < b.size(); i++){
			q += b[i] / 2;
		}
		if (m <= q) q = 2 * m;
		else{
			m -= q; q = 2 * q; 
			for(int i = 0; m && i < b.size(); i++){
				if (b[i] & 1){
					m--, q++;
				}
			}
		}
	}
	printf("%d %d\n", p, q);
}

void printans(){

}


int main(){
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