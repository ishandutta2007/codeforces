#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int main(){
    int t = 1, n, k;
    // sd(t);
    while(t--){
        sd(n); sd(k);
        int a[300];
        int ans = 0;
        int present = 0;
        for(int i = 1; i <= n; i++){
        	sd(a[i]);
        	present += a[i];
        	int x = min(present, 8);
        	ans += x;
        	if(ans >= k){
        		printf("%d\n", i);
        		return 0;
        	}
        	present -= x;
        }
        printf("-1");
    }
}