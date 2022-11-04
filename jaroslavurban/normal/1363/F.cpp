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

#define inf int(2e9)
#define N 2002
string s,t;
int n;
int suf[26][N],suf2[26][N];
int dp[N][N];

int solvedp(int i,int j){
	if(dp[i][j]!=inf)return dp[i][j];
	if(!j)return dp[i][j]=0;
	int &res=dp[i][j];
	if(i){
		if(s[i-1]==t[j-1])res=min(res,solvedp(i-1,j-1));
		res=min(res,1+solvedp(i-1,j));
	}
	int c=t[j-1]-'a';
	if(suf[c][i]>suf2[c][j])res=min(res,solvedp(i,j-1));
	return res;
}

int main(){
	int tt;cin>>tt;
	for(int tc=0;tc<tt;++tc){
		cin>>n>>s>>t;
		memset(suf,0,sizeof(suf));
		memset(suf2,0,sizeof(suf2));
		for(int i=0;i<n+2;++i)
			for(int j=0;j<n+2;++j)
				dp[i][j]=inf;
		for(int i=n-1;i>=0;--i){
			for(int j=0;j<26;++j){
				suf[j][i]=suf[j][i+1];
				suf2[j][i]=suf2[j][i+1];
			}
			++suf[s[i]-'a'][i];
			++suf2[t[i]-'a'][i];
		}
		int res=solvedp(n,n);
		if(res>=inf)cout<<-1<<endl;
		else cout<<res<<endl;
	}
}