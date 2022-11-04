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

const int N=200010;
int n,a[N],b[N];
int tr(int diff){
	int del=0;
	for(int i=0;i+1<n;++i){
		if(a[i+1]-a[i]!=diff&&del)return -1;
		if(a[i+1]-a[i]!=diff&&!del){
			del=i+2;
			if(!i&&n>=3&&a[2]-a[1]==diff){del=1;continue;}
			if(i+2>=n)return del;
			if(a[i+2]-a[i]!=diff)return -1;
			++i;
		}
	}
	return del?del:1;
}

int main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)b[i]=a[i];
	sort(a,a+n);
	set<int>d;
	for(int i=0;i<n-1;++i)d.insert(a[i+1]-a[i]);
	if(d.size()>3){cout<<-1<<endl;return 0;}
	for(auto it=d.begin();it!=d.end();++it){
		int res=tr(*it);
		if(~res){
			for(int i=0;i<n;++i)if(b[i]==a[res-1]){cout<<i+1<<endl;break;}
			return 0;
		}
	}
	cout<<-1<<endl;
}