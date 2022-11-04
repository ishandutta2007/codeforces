#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

int n,k=1,x;
bool l[1000];
bool f[1000];
int main(){
	cin>>n;
	for(int i=2;i<n;++i)if(n-n/i-!!(n%i)-i+1>n-n/k-!!(n%k)-k+1)k=i;
	for(int i=0;i<n;i+=k)f[i]=true;
	while(n>3){
		int cnt=0;
		for(int i=0;i<n;++i)if(!f[i]&&!l[i])++cnt;
		if(cnt==k-1)break;
		vector<int>p;
		for(int i=0;i<n&&p.size()!=k;++i)if(!f[i]&&!l[i]){p.push_back(i);l[i]=true;}
		cout<<k<<endl;
		for(int i=0;i<k;++i)cout<<p[i]+1<<" ";
		cout<<endl;
//		for(int i=0;i<n;++i)cout<<l[i]<<" ";
//		cout<<endl;
		cin>>x;if(x==-1)return 0;--x;
		for(int i=x;i<x+k;++i)l[i%n]=false;
	}
	cout<<0<<endl;
}