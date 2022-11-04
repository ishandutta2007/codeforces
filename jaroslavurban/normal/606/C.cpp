#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int n;
int idx[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int a;cin>>a;idx[--a]=i;
	}
	int bst=1;
	int cur=1;
	for(int i=0;i<n-1;++i)
		if(idx[i+1]>idx[i])++cur;
		else {
			bst=max(bst,cur);
			cur=1;
		}
	bst=max(bst,cur);
	cout<<n-bst<<endl;
}