#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

const int N = 1000006;
int a[N];
ordered_set os;
int n;
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]);
	int ret = n & 1;
	for(int i = n; i >= 1; i--) ret ^= (os.order_of_key(a[i]) & 1), os.insert(a[i]);
	printf(ret ? "Um_nik\n" : "Petr\n");
}