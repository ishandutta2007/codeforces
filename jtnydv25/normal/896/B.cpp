#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
int A[1005];
int main(){
	int n, m, c;
	cin >> n >> m >> c;
	int lft = 0, rgt = n + 1;
	while(lft + 1 < rgt){
		int x;
		cin >> x;
		if(2 * x <= c){
			if(lft == 0 || x >= A[lft]){
				A[++lft] = x;
				printf("%d\n", lft);
				fflush(stdout);
				continue;
			}
			int lo = 1, hi = lft;
			while(lo < hi){
				int mid = (lo + hi) >> 1;
				if(A[mid] > x){
					hi = mid;
				}
				else lo = mid + 1;
			}
			A[lo] = x;
			printf("%d\n", lo);
			fflush(stdout);
		}
		else{
			if(rgt == n + 1 || x <= A[rgt]){
				A[--rgt] = x;
				printf("%d\n", rgt);
				fflush(stdout);
				continue;
			}
			int lo = rgt, hi = n;
			while(lo < hi){
				int mid = (lo + hi + 1) >> 1;
				if(A[mid] < x){
					lo = mid;
				}
				else hi = mid - 1;
			}
			A[lo] = x;
			printf("%d\n", lo);
			fflush(stdout);
		}
	}
}