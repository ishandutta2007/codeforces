#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=100010;
int a[N];
int n;
bool tr(int diff){
	int st=0;
	int cur=0;
	bool pos=true;
	for(int i=0;pos&&a[i];++i){
		int first=cur;
		bool swapped=false;
		int left=a[i];
		while(left&&cur<n){
			cur+=diff+1;
			--left;
		}
		if(cur>=n)cur=++st;
		while(left){
			if(cur>first){
				pos=false;
				break;
			}
			--left;
			cur+=diff+1;
		}
	}
//	cerr<<diff<<" "<<pos<<endl;
	return pos;
}
		
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=0;i<n;++i){
			int num;cin>>num;
			++a[num];
		}
		sort(a,a+n+1);
		reverse(a,a+n+1);
		int l=0,r=n-1;
		while(l<r){
			int mid=(l+r)/2;
			if(tr(mid))l=mid+1;
			else r=mid;
		}
		if(tr(l))cout<<l<<endl;
		else cout<<l-1<<endl;
	}
}