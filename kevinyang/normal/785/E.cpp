#include <bits/stdc++.h>
using namespace std;
int sq = 450;
vector<vector<int>>dp(451,vector<int>(200001));
void update(int i, int x, int val){
	for(int a = x; a<=200000; a+=a&-a){
		dp[i][a]+=val;
	}
}
int query(int i, int x){
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		sum+=dp[i][a];
	}
	return sum;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		arr[i] = i;
		int bucket = (i-1)/sq + 1;
		update(bucket,i,1);
	}
	long long ans = 0;
	while(q--){
		int l,r;
		cin >> l >> r;
		if(l==r){
			cout << ans << "\n";
			continue;
		}
		if(l>r)swap(l,r);
		if(true){
			int cur = l+1;
			while(cur%sq!=1&&cur<r){
				int v = arr[cur];
				if(arr[l]>v)ans--;
				else ans++;
				cur++;
			}
			while(cur+sq<=r){
				int bucket = (cur-1)/sq+1;
				int v = query(bucket,arr[l]);
				int v2 = query(bucket,n)-v;
				ans-=v;
				ans+=v2;
				cur+=sq;
			}
			while(cur+1<=r){
				int v = arr[cur];
				if(arr[l]>v)ans--;
				else ans++;
				cur++;
			}
		}
		if(true){
			int cur = l+1;
			while(cur%sq!=1&&cur<r){
				int v = arr[cur];
				if(arr[r]>v)ans++;
				else ans--;
				cur++;
			}
			while(cur+sq<=r){
				int bucket = (cur-1)/sq+1;
				int v = query(bucket,arr[r]);
				int v2 = query(bucket,n)-v;
				ans-=v2;
				ans+=v;
				cur+=sq;
			}
			while(cur+1<=r){
				int v = arr[cur];
				if(arr[r]>v)ans++;
				else ans--;
				cur++;
			}
		}
		if(arr[l]>arr[r])ans--;
		else ans++;
		if(true){
			int bucket = (l-1)/sq+1;
			update(bucket,arr[l],-1);
			update(bucket,arr[r],1);
			bucket = (r-1)/sq+1;
			update(bucket,arr[r],-1);
			update(bucket,arr[l],1);
			swap(arr[l],arr[r]);
		}
		cout << ans << "\n";
	}
	return 0;
}