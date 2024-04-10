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

const int N=4020;
string s[N];
int dp[N][N];
int n,m;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	int dy[4]={0,-1,-2,-2};
	int dx[4]={-2,-1,-2,0};
	int res=0;
	for(int i=0;i<n;++i)cin>>s[i];
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			if((i+j)%2==m%2){
				int y=(i+j-m)/2;
				int x=(j-i+m)/2;
				if(y>=0&&x>=0&&y<n&&x<m){
					int mn=1e9;
					for(int k=0;k<4;++k){
						int ni=i+dy[k];
						int nj=j+dx[k];
						int ny=(ni+nj-m)/2;
						int nx=(nj-ni+m)/2;
						if(ny>=0&&nx>=0&&ny<n&&nx<m&&s[ny][nx]==s[y][x]
							&&ni>=0&&nj>=0&&ni<N&&nj<N)mn=min(mn,dp[ni][nj]);
						else mn=-1;
					}
					if(~mn)dp[i][j]=mn+1;
					else dp[i][j]=1;
					res+=dp[i][j];
				}
			}
	cout<<res<<endl;
}