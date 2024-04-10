#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))

const int N = 5e4 + 10;
const int K = 11;
const int INF = 2e9;
int arr[K];
int n, k;
struct data{
	int mn[K], mx[K], sz = 0;
	data(){
		for(int i = 1; i <= k; i++)
			mn[i] = mx[i] = arr[i];
		sz = 1;
	}

	bool operator < (const data & data2) const{
		for(int i = 1; i <= k; i++){
			if(mx[i] >= data2.mn[i])
				return 0;
		}
		return 1;
		return mn[1] < data2.mn[1];
	}

	void merge(const data & data2){
		sz += data2.sz;
		for(int i = 1; i <= k; i++){
			mn[i] = min(mn[i], data2.mn[i]);
			mx[i] = max(mx[i], data2.mx[i]);
		}
	}
};

set<data> myst;
vector<data> deletions;

void Insert(data D){
	if(myst.empty()){
		myst.insert(D);
		return;
	}

	auto it  = myst.lower_bound(D);
	data final = D;
	deletions.clear();
	while(it != myst.end() && !((*it) < D) && !(D < (*it))){
		deletions.push_back(*it);
		final.merge(*it);		
		it++;
	}
	for(auto x : deletions){
		myst.erase(x);
	}
	myst.insert(final);
}
int main(){
	sd(n); sd(k);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			sd(arr[j]);
		}
		data D = data();
		Insert(D);
		printf("%d\n", (*myst.rbegin()).sz);
	}	
}