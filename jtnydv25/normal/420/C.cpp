#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T pair<int, int>
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 3e5 + 10;
int x[N], y[N];
int freq[N];
map<int, int> F[N];
int z = 0;
ordered_set os;
int main(){
	int n, p; sd(n), sd(p);
	for(int i = 1; i <= n; i++){
		sd(x[i]); sd(y[i]);
		if(x[i] > y[i])
			swap(x[i], y[i]);
		F[x[i]][y[i]]++;
		freq[x[i]]++;
		freq[y[i]]++;
	}
	long long cnt = 0;
	for(int i = n; i >= 1; i--){
		cnt += (os.size() - os.order_of_key({p - freq[i], -1}));
		os.insert({freq[i], ++z});
	}

	// cerr << cnt << endl;

	for(int i = 1; i <= n; i++){
		for(auto it : F[i]){
			int j = it.first;
			int added = freq[i] + freq[j] >= p;
			int shouldbeadded = freq[i] + freq[j] - it.second >= p;
			cnt += shouldbeadded - added;
		}
	}

	printf("%lld\n", cnt);
}