#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define F first
#define S second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set os;
const int N = 100005;
int p[N];
int pref[N];
int cnt[N];
int main(){
	int n;
	sd(n);
	int mx = 0;
    for(int i = 1; i <= n; i++){
    	sd(p[i]);
    	mx = max(mx, p[i]);
    	pref[i] = pref[i - 1] + (mx == p[i]);
    	cnt[i] = os.size() - os.order_of_key(p[i]);
    	os.insert(p[i]);
    }
    os.clear();
    mx = -1;
    int ans = 1000000000;
    for(int i = n; i >= 1; i--){
    	int res = pref[i - 1] + os.order_of_key(p[i]) + n - pref[i];
    	if(cnt[i] == 1) os.insert(p[i]);
    	if(res > mx) ans = p[i];
    	else if(res == mx && p[i] < ans) ans = p[i];	
    	mx = max(mx, res);
    }
    printf("%d\n", ans);
}