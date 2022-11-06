#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int p,q;
		cin >> p >> q;
		
		int pp= p;
		if(p%q!=0){
			cout << p << "\n";
			continue;
		}
		set<int>s;
		map<int,int>hm;
		for(int i = 2; i*i<=q; i++){
			while(q%i==0){
				s.insert(i);
				hm[i]++;
				q/=i;
			}
		}
		if(q>1){
			s.insert(q);
			hm[q]++;
		}
		int ans = pp;
		for(int nxt: s){
			int cnt = 0;
			while(p%nxt==0){
				p/=nxt;
				cnt++;
			}
			ans = min(ans,(int)pow(nxt,cnt+1-hm[nxt]));
		}
		cout << pp/ans << "\n";
	}
	return 0;
}