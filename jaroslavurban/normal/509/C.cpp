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

const int N=303;
int n;
int b[N];
vector<int>a[N];

void add(int idx,int cnt){
	a[idx]=a[idx-1];
	int c=cnt;
	for(int i=0;c&&i<a[idx].size();++i)
		while(c&&a[idx][i]<9){
			++a[idx][i];
			--c;
		}
	for(int i=a[idx-1].size()+1;c;++i){
		c=b[idx]-1;
		a[idx].assign(i,0);
		a[idx][i-1]=1;
		for(int j=0;c&&j<a[idx].size();++j)
			while(c&&a[idx][j]<9){
				++a[idx][j];
				--c;
			}
	}
}

void sub(int idx,int cnt){
	int done=0;
	a[idx]=a[idx-1];
	for(int i=a[idx].size()-1;i>=0;--i)done+=a[idx][i];
	for(int i=1;i<a[idx-1].size();++i){
		done-=a[idx-1][i-1];
		if(a[idx-1][i]==9)continue;
		a[idx]=a[idx-1];
		++a[idx][i];
		for(int j=0;j<i;++j)a[idx][j]=0;
		int c=b[idx]-done-1;
		for(int j=0;c>0&&j<i;++j)
			while(c>0&&a[idx][j]<9){
				++a[idx][j];
				--c;
			}
		if(c==0)return;
	}
	a[idx].assign(a[idx-1].size()+1,0);
	a[idx][a[idx-1].size()]=1;
	int c=b[idx]-1;
	for(int i=0;i<a[idx].size()&&c;++i)
		while(c&&a[idx][i]<9){
			++a[idx][i];
			--c;
		}
}


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>b[i];
	int cnt=b[0];
	while(cnt){a[0].push_back(min(9,cnt));cnt-=min(9,cnt);}
	for(int i=1;i<n;++i)
		if(b[i]>b[i-1])add(i,b[i]-b[i-1]);
		else sub(i,b[i-1]-b[i]);
	for(int i=0;i<n;++i,cout<<endl)
		for(int j=a[i].size()-1;j>=0;--j)
			cout<<a[i][j];
}