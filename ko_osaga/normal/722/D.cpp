#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;

set<int> s;
int n, a[100050];

bool trial(int x){
	s.clear();
	for(int i=0; i<n && a[i]<=x; i++){
		s.insert(a[i]);
	}
	for(int i=n-1; i>=0 && a[i]>x; i--){
		int v = a[i];
		while(v > x) v /= 2;
		bool ok = 0;
		for(int j=v; j>=1; j/=2){
			if(s.find(j) == s.end()){
				s.insert(j);
				ok = 1;
				break;
			}
		}
		if(!ok) return 0;
	}
	return 1;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	sort(a, a+n);
	for(int i=n-1; i>=0; i--){
		s.insert(a[i]);
	}
	int s = 1, e = 1e9;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m+1;
	}
	trial(s);
	for(auto &i : ::s) printf("%d ", i);
}