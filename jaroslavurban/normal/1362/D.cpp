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

struct blog{
	int want,id;
	bool done;
	vector<blog*>c;
	bool operator<(const blog &other){
		return want < other.want;
	}
};

int main(){
	int n,m;cin>>n>>m;
	vector<blog*>blogs(n);
	for(int i=0;i<n;++i)
		blogs[i] = new blog;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;
		--u;--v;
		blogs[u]->c.push_back(blogs[v]);
		blogs[v]->c.push_back(blogs[u]);
	}
	for(int i=0;i<n;++i){
		blogs[i]->id=i+1;
		blogs[i]->done=false;
		cin>>blogs[i]->want;
	}
	sort(blogs.begin(),blogs.end(),[&](blog *a,blog *b){
		return *a<*b;
	});
	bool pos=true;
	for(int i=0;i<n;++i){
		int sz=blogs[i]->want;
		vector<bool>nums(sz);	
		for(auto b:blogs[i]->c)
			if(b->done&&b->want<=sz)
				nums[b->want-1]=true;
		for(int j=0;j<blogs[i]->want-1;++j)
			if(!nums[j]){
				pos=false;
				break;
			}
		if(nums[blogs[i]->want-1])pos=false;
		if(!pos)break;
		blogs[i]->done=true;
	}
	if(!pos)cout<<-1<<endl;
	else{
		for(int i=0;i<n;++i)
			cout<<blogs[i]->id<<" ";
		cout<<endl;
	}
	for(int i=0;i<n;++i)
		delete blogs[i];
}