//Author: HeXun
//Date: 10-20-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 320000;
char s[maxn];
int sum[maxn];
int fsum[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	cin >> (s + 1);
	for(int i = 1; i <= n; i += 1)
		if(s[i] == '(') sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1] - 1;
	//for(int i = 1; i <= n; i += 1) cout << sum[i] << " ";
	//cout << endl;
	if(sum[n]) cout << "0\n1 1";
	else{
		int mi = 0;
		for(int i = 1; i <= n; i += 1) mi = min(sum[i], mi);
		int ans = 0;
		for(int i = 1; i <= n; i += 1) ans += mi == sum[i];
		int L = n, R = 1;
		for(int i = 1; i <= n; i += 1) if(mi == sum[i]){
			L = min(L, i);
			R = max(R, i);
		}
		int ians = -1, l = -1, r = -1;
		for(int i = L; i; i -= 1) if(s[i] == ')'){
			 l = i;
			 break;
		}
		for(int i = R + 1; i <= n; i += 1) if(s[i] == '('){
			r = i;
			break;
		}
		if(~l and ~r){
			ians = 0;
			for(int i = 1; i <= n; i += 1){
				fsum[i] = sum[i];
				if(i >= l and i < r) fsum[i] += 2;
			}
			int fmi = 0;
			for(int i = 1; i <= n; i += 1) fmi = min(fsum[i], fmi);
			for(int i = 1; i <= n; i += 1) ians += fmi == fsum[i];
		}
		int xL = n, xR = 1;
		for(int i = 1; i <= n; i += 1) if(mi == sum[i] or mi == sum[i] - 1){
			xL = min(xL, i);
			xR = max(xR, i);
		}
		int xians = -1, xl = -1, xr = -1;
		for(int i = xL; i; i -= 1) if(s[i] == ')'){
			 xl = i;
			 break;
		}
		for(int i = xR + 1; i <= n; i += 1) if(s[i] == '('){
			xr = i;
			break;
		}
		if(~xl and ~xr){
			xians = 0;
			for(int i = 1; i <= n; i += 1){
				fsum[i] = sum[i];
				if(i >= xl and i < xr) fsum[i] += 2;
			}
			int fmi = 0;
			for(int i = 1; i <= n; i += 1) fmi = min(fsum[i], fmi);
			for(int i = 1; i <= n; i += 1) xians += fmi == fsum[i];
		}
		int dans = -1, dl = -1, dr = -1;
		for(int L = 1, R = 1; L <= n; L = R += 1){
			if(sum[L] == mi) continue;
			while(sum[R] != mi and R <= n) R += 1;
			int l = -1, r = -1;
			for(int i = L; i <= R and i <= n; i += 1){
				if(s[i] == '(') if(not ~l) l = i;
				if(s[i] == ')') r = i;
			}
			if(l < r and ~l and ~r){
				int pdans = 0;
				for(int i = l; i < r; i += 1) if(sum[i] - 1 == mi) pdans += 1;
				if(pdans > dans){
					dans = pdans;
					dl = l;
					dr = r;
				}
				//cout << pdans << " " << l << " " << r << endl;
			}
		}
		for(int L = 1, R = 1; L <= n; L = R += 1){
			if(sum[L] == mi or sum[L] == mi + 1) continue;
			while((sum[R] != mi and sum[R] != mi + 1) and R <= n) R += 1;
			int l = -1, r = -1;
			for(int i = L; i <= R and i <= n; i += 1){
				if(s[i] == '(') if(not ~l) l = i;
				if(s[i] == ')') r = i;
			}
			if(l < r and ~l and ~r){
				int pdans = ans;
				for(int i = l; i < r; i += 1) if(sum[i] - 2 == mi) pdans += 1;
				if(pdans > dans){
					dans = pdans;
					dl = l;
					dr = r;
				}
				//cout << pdans << " " << l << " " << r << endl;
			}
		}
		if(ians > dans){
			dans = ians;
			dl = l;
			dr = r;
		}
		if(xians > dans){
			dans = xians;
			dl = xl;
			dr = xr;
		}
		if(ans > dans){
			dans = ans;
			dl = 1;
			dr = 1;
		}
		cout << dans << "\n" << dl << " " << dr;
	}
	return 0;
}