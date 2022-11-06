#include <bits/stdc++.h>
using namespace std;
#define int long long
const int sq = 500;
const int n = (int)2e5+sq*5;
vector<int>vis(n+1);
vector<int>val(sq);
vector<int>lazy(sq);
vector<int>cnt(sq);
vector<int>arr(n+1);
int q,d;
int ans = 0;
int get(int x){
	return arr[x]+lazy[x/sq]; 
}
int query(int l, int r){
	int sum = 0;
	while(l<=r&&l%sq!=0){
		if(vis[l]){
			sum++;
		}
		l++;
	}
	while(l%sq==0&&l+sq<=r){
		sum+=cnt[l/sq];
		l+=sq;
	}
	while(l<=r){
		if(vis[l]){
			sum++;
		}
		l++;
	}
	return sum;
}
void add(int x){
	int i = x;
	int r = x+d;
	r = min(r,200500LL);
	while(i<=r&&i%sq!=0){
		if(vis[i]){
			ans+=get(i); arr[i]++; val[i/sq]++;
		}
		i++;
	}
	while(i%sq==0&&i+sq<=r){
		ans+=val[i/sq]; val[i/sq]+=cnt[i/sq]; lazy[i/sq]++;
		i+=sq;
	}
	while(i<=r){
		if(vis[i]){
			ans+=get(i);
			arr[i]++; val[i/sq]++;
		}
		i++;
	}
	int sum = query(max(0LL,x-d),x);
	ans+=sum*(sum-1)/2;
	arr[x] = sum-lazy[x/sq];
	val[x/sq]+=sum;
	cnt[x/sq]++;
	vis[x] = 1;
}
void rem(int x){
	int i = x+1;
	int r = x+d;
	r = min(r,200500LL);
	while(i<=r&&i%sq!=0){
		if(vis[i]){
			arr[i]--; val[i/sq]--;
			ans-=get(i);
		}
		i++;
	}
	while(i%sq==0&&i+sq<=r){
		val[i/sq]-=cnt[i/sq]; lazy[i/sq]--; ans-=val[i/sq];
		i+=sq;
	}
	while(i<=r){
		if(vis[i]){
			arr[i]--; val[i/sq]--;
			ans-=get(i);
		}
		i++;
	}

	int sum = query(max(0LL,x-d),x-1);
	//cout << sum << "\n";
	ans-=sum*(sum-1)/2;
	arr[x] = 0;
	val[x/sq]-=sum;
	cnt[x/sq]--;
	vis[x] = 0;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> q >> d;
	for(int i = 1; i<=q; i++){
		int x;
		cin >> x;
		if(vis[x]){
			rem(x);
		}
		else{
			add(x);
		}
		cout << ans << "\n";
	}
	return 0;
}