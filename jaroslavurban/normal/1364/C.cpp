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

const int N=100001;

int n;
int a[N];
int b[N];
int ist[N];
bool filled[N];
int main(){
	cin>>n;
	for(int i=0;i<n;++i){cin>>a[i];++ist[a[i]];}
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=0;i<N;++i)if(!ist[i])q.push(i);
	int fp=0;
	int cnt=0;
	while(!q.empty()&&cnt<n){
		int bb=q.top();q.pop();
		b[cnt]=bb;
		filled[bb]=true;
		for(;filled[fp];++fp){}
		if(fp!=a[cnt]){
			cout<<-1<<endl;
			return 0;
		}
		if(!--ist[a[cnt]])q.push(a[cnt]);
		++cnt;
	}
	if(cnt!=n)cout<<-1<<endl;
	else{
		for(int i=0;i<n;++i)cout<<b[i]<<" ";
		cout<<endl;
	}
}