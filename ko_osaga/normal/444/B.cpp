#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int d, n;
lint x;
int a[100005], b[100005];

lint getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

int nxt[100005];
void initAB() {
	int i;
	for(i = 0; i < n; i = i + 1){
		a[i] = i + 1;
	}
	for(i = 0; i < n; i = i + 1){
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for(i = 0; i < n; i = i + 1){
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for(i = 0; i < n; i = i + 1){
		swap(b[i], b[getNextX() % (i + 1)]);
	}
	nxt[n] = n;
	for(int i=n-1; i>=0; i--){
		if(b[i]) nxt[i] = i;
		else nxt[i] = nxt[i+1];
	}
}

vector<pi> proc;
set<int> s;
int ret[100005];

int main(){
	cin >> n >> d >> x;
	initAB();
	for(int i=0; i<n; i++){
		proc.push_back({a[i], i});
		s.insert(i);
	}
	sort(proc.begin(), proc.end());
	reverse(proc.begin(), proc.end());
	for(auto &i : proc){
		auto it = s.lower_bound(nxt[0] + i.second);
		while(it != s.end()){
			int pos = *it;
			if(b[pos - i.second]){
				ret[pos] = i.first;
				s.erase(it);
			}
			it = s.lower_bound(nxt[pos+1-i.second]+i.second);
		}
	}
	for(int i=0; i<n; i++){
		printf("%d\n", ret[i]);
	}
}