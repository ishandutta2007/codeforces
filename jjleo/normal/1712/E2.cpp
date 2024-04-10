#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

typedef long long ll;

ll a[maxn];

inline void add(int x, int y){
	for(;x;x -= x & -x) a[x] += y;
}

inline ll query(int x){
	ll sum = 0;
	for(;x < maxn;x += x & -x) sum += a[x];
	return sum;
}

int n;
ll ans[maxn];
vector<int> v[maxn];
vector<pair<int, int> > w[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		int l, r;
		scanf("%d%d", &l, &r);
		ans[i] = 1ll * (r - l + 1) * (r - l + 1 - 1) * (r - l + 1 - 2) / 6;
		w[r].push_back({l, i});
	}
	for(int i = 1;i < maxn / 2;i++){
        for(int j = i;j < maxn;j += i) v[j].push_back(i);
    }
    for(int i = 3;i < maxn / 2;i++){
    	vector<int> &a = v[i * 2];
    	int pos = 0;
    	while(pos + 1 < a.size() && a[pos + 1] < i) pos++;
    	int Pos = pos;
    	for(int j = 0;j + 1 < a.size() && a[j + 1] < i;j++){
    		if(j == pos) pos++; 
    		while(pos - 1 > j && a[j] + a[pos - 1] + i > i * 2) pos--;
			if(a[j] + a[pos] + i > i * 2) add(a[j], Pos - pos + 1);
		}
		{
			vector<int> &a = v[i];
	    	int pos = 0;
	    	while(pos + 1 < a.size() && a[pos + 1] < i) pos++;
	    	int Pos = pos;
	    	for(int j = 0;j + 1 < a.size() && a[j + 1] < i;j++){
	    		if(j == pos) pos++; 
	    		while(pos - 1 > j && a[j] + a[pos - 1] + i > i * 2) pos--;
				if(a[j] + a[pos] + i > i * 2) add(a[j], -(Pos - pos + 1));
			}
			for(int j = 0;j + 1 < a.size() && a[j + 1] < i;j++){
				add(a[j], Pos - j);
			}
		}
		for(auto it : w[i]){
			ans[it.second] -= query(it.first); 
		}
	}
    for(int i = 1;i <= n;i++) printf("%lld\n", ans[i]);
}