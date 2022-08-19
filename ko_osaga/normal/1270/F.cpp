#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;
const int MAXN = 200005;
const int B = 400;
using pi = pair<int, int>;
using lint = long long;

int n;
char str[MAXN];

lint naive(){
	lint ans = 0;
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=i; j<=n; j++){
			if(str[j] == '1') cnt++;
			if(cnt && (j - i + 1) % cnt == 0) ans++;
		}
	}
	return ans;
}

int main(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	lint ret = 0;
	for(int i=1; i<=B&&i<=n; i++){
		vector<int> vt = {0};
		int cursum = 0;
		for(int j=1; j<=n; j++){
			if(str[j] == '0') cursum--;
			else cursum += i - 1;
			vt.push_back(cursum);
		}
		sort(all(vt));
		for(int i=0; i<sz(vt); ){
			int e = i;
			while(e < sz(vt) && vt[i] == vt[e]) e++;
			ret += 1ll * (e - i) * (e - i - 1) / 2;
			i = e;
		}
	}
	vector<int> pos;
	for(int i=1; i<=n; i++){
		if(str[i] == '1') pos.push_back(i);
	}
	for(int i=1; i<=n/B; i++){
		for(int j=0; j+i-1<sz(pos); j++){
			int s2 = pos[j];
			int e2 = pos[j + i - 1];
			int s1 = (j ? pos[j-1] : 0) + 1;
			int e1 = (j + i < sz(pos) ? pos[j+i] : (n+1)) - 1;
			int base = e2 - s2 + 1;
			int x = s2 - s1;
			int y = e1 - e2;
			auto solve = [&](int start){
				int os = start;
				start = max(start, (B + 1) * i);
				start = (start + i - 1) / i;
				int end = n / i;
				lint ret = 0;
				if(start <= end){
					ret += 1ll * i * (1ll * (end - start + 1) * (end + start) / 2);
					ret -= 1ll * (os - 1) * (end - start + 1);
				}
				return ret;
			};
			ret += solve(base) - solve(base + x + 1) 
			- solve(base + y + 1) + solve(base + x + y + 2);
		}
	}
	cout << ret << endl;
}