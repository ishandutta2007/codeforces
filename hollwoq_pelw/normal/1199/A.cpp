#include <bits/stdc++.h>
using namespace std;

bool check(int p, int a[], int n, int x, int y){
	for(int i=p+1, up=min(p+y,n-1); i<=up; ++i) if(a[p]>a[i])return 0;
	for(int i=p-1, up=max(p-x,0); i>=up; --i) if(a[p]>a[i])return 0;
	return 1;
}
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    int a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i){
		if(check(i, a, n, x, y))return cout<<i+1 ,0;
	}
	return 0;
}