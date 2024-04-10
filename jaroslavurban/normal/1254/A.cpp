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

const int N=110;
string f[N];
char res[N][N];
int n,m,k,r;
int y,x,cur,up,def;

void nxt(){
	++cur;
	while(!isdigit(cur+'0')&&!isalpha(cur+'0'))++cur;
	int cnt=def+!!up;
	if(up)--up;
	for(;cnt&&y<n;++y,x=min(m-1,max(0,x))){
		if(y%2==0)
			while(cnt&&x<m){
				res[y][x]=cur;
				if(f[y][x]=='R')--cnt;
				++x;
			}
		else
			while(cnt&&x>=0){
				res[y][x]=cur;
				if(f[y][x]=='R')--cnt;
				--x;
			}
		if(!cnt)break;
	}
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m>>k;
		for(int i=0;i<n;++i)cin>>f[i];
		r=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				r+=(f[i][j]=='R');
		def=r/k;
		up=r%k;
		y=0,x=0,cur=-1;
		memset(res,-1,sizeof(res));
		for(int i=0;i<k;++i)nxt();
		for(int i=0;i<n;++i,cout<<endl)
			for(int j=0;j<m;++j)
				if(res[i][j]==-1)cout<<char('0'+cur);
				else cout<<char(res[i][j]+'0');
	}
}