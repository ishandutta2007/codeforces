#include <bits/stdc++.h>
using namespace std;
const int sq = 350;
int freq[sq][100005];
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	vector<int>val(n+1);
	vector<deque<int>>dq(n+1);
	for(int i = 0; i<n; i++){
		dq[i/sq].push_back(i);
		val[i/sq]+=arr[i];
		freq[i/sq][arr[i]]++;
	}
	int q;
	cin >> q;
	int lastans = 0;
	while(q--){
		int cm;
		cin >> cm;
		if(cm==1){
			int l,r;
			cin >> l >> r;
			l = ((l+lastans-1)%n)+1;
			r = ((r+lastans-1)%n)+1;
			l--; r--;
			if(l>r)swap(l,r);
			if(l/sq==r/sq){
				vector<int>a;
				for(int nxt: dq[l/sq]){
					a.push_back(nxt);
				}
				int v = a[r%sq];
				for(int i = r%sq; i>l%sq; i--){
					a[i] = a[i-1];
				}
				a[l%sq] = v;
				dq[l/sq].clear();
				for(int nxt: a){
					dq[l/sq].push_back(nxt);
				}
				continue;
			}
			
			stack<int>stk;
			while(dq[r/sq].size()>r%sq){
				int v = dq[r/sq].back();
				dq[r/sq].pop_back();
				stk.push(v);
			}
			int v = stk.top();
			freq[r/sq][arr[v]]--;
			stk.pop();
			while(stk.size()){
				dq[r/sq].push_back(stk.top());
				stk.pop();
			}
			assert(stk.size()==0);
			while(dq[l/sq].size()>l%sq){
				int v = dq[l/sq].back();
				dq[l/sq].pop_back();
				stk.push(v);
			}
			freq[l/sq][arr[v]]++;
			dq[l/sq].push_back(v);
			while(stk.size()){
				dq[l/sq].push_back(stk.top());
				stk.pop();
			}
			for(int i = l/sq+1; i<=r/sq; i++){
				int v = dq[i-1].back();
				dq[i-1].pop_back();
				freq[i-1][arr[v]]--;
				freq[i][arr[v]]++;
				dq[i].push_front(v);
			}
			assert(dq[l/sq].size()==sq);
		}
		else{
			int l,r,k;
			cin >> l >> r >> k;
			l = ((l+lastans-1)%n)+1;
			r = ((r+lastans-1)%n)+1;
			k = ((k+lastans-1)%n)+1;
			l--;r--;
			if(l>r)swap(l,r);
			int cur = l;
			int ans = 0;
			while(cur%sq!=0&&cur<=r){
				int v = arr[dq[cur/sq][cur%sq]];
				if(v==k)ans++;
				cur++;
			}
			while(cur%sq==0&&cur+sq<r){
				int v = freq[cur/sq][k];
				ans+=v;
				cur+=sq;
			}
			while(cur<=r){
				int v = arr[dq[cur/sq][cur%sq]];
				if(v==k)ans++;
				cur++;
			}
			lastans = ans;
			cout << ans << "\n";
		}
	}
	return 0;
}