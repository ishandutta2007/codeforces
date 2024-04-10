#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 10;
const int MM = 1e9 + 7;

map<int, int> s;

int a[MAXN], f[MAXN];

int gcd(int p, int q){
	return q ? gcd(q, p % q) : p;
}

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n * n; i++){
		int x;
		scanf("%d", &x);
		auto Nico = s.find(x);
		if (Nico == s.end()){
			s[x] = 1;
		}
		else{
			(Nico->second)++;
		}
	}
	for(int i = 1; i <= n; i++){
		f[i] = (s.rbegin()) -> first;
		s[f[i]]++;
		for(int j = 1; j <= i; j++){
			int tmp = gcd(f[i], f[j]);
			auto Nico = s.find(tmp);
			if (Nico -> second == 2){
				s.erase(Nico);
			}
			else
				(Nico->second) -= 2;
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%d%c", f[i], " \n"[i == n]);
	/*
	sort(a + 1, a + n * n + 1);
	int cnt = 0, now = a[1], tmp = 1;
	for(int i = 1; i <= n * n; i++)
		if (a[i] == now)
			tmp++;
		else{
			if (tmp & 1){
				f[++cnt] = now;
			}
			now = a[i];
		}	
	for(int i = 1; i <= cnt; i++)
		for(int j = 1; j <= cnt; j++){
			s[gcd(f[i], f[j])]--;
		}
	*/
	return 0;
}