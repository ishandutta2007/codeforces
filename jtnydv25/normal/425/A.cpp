#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";


const int N = 1e5 + 10;
int a[N], pref[N];

multiset<int> st1, st2;
int main(){
	int n, K;
	sd(n);sd(K);
	for(int i = 1; i <= n; i++) sd(a[i]), pref[i] = pref[i - 1] + a[i];
	int ans = -10005;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			st1.clear();
			st2.clear();	
			int sm =0 ;
			for(int k = 1; k <= n; k++){
				if(k >= i && k <= j) st1.insert(a[k]), sm += a[k];
				else st2.insert(-a[k]);
			}
			int iter = 0;
			while(iter < K && !st1.empty() && !st2.empty()){
				if(*st1.begin() + *st2.begin() < 0){
					sm -= (*st1.begin() + *st2.begin());
					iter++;
					st1.erase(st1.begin());
					st2.erase(st2.begin());
				}
				else break;
			}
			ans = max(ans, sm);
		}
	}
	printf("%d\n", ans);
}