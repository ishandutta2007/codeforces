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

const int N=301;
int b[N][N];
int main(){
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		int n,m;cin>>n>>m;
		memset(b,0,sizeof(b));
		bool pos=true;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>b[i][j];
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if((!i&&!j)||(!i&&j==m-1)||(i==n-1&&!j)||(i==n-1&&j==m-1)){
					if(b[i][j]>2)pos=false;
					b[i][j]=2;
				}
				else if(i==0||j==0||i==n-1||j==m-1){
					if(b[i][j]>3)pos=false;
					b[i][j]=3;
				}
				else{
					if(b[i][j]>4)pos=false;
					b[i][j]=4;
				}
			}
		if(!pos){cout<<"NO\n";continue;}
		cout<<"YES\n";
		for(int i=0;i<n;++i,cout<<endl)
			for(int j=0;j<m;++j)
				cout<<b[i][j]<<" ";
	}
}