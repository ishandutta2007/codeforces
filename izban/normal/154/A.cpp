#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <set>
#include <sstream>
#include <queue>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

const int maxn=100100,inf=1e9+7;

string s,s1;
int n;
int d[maxn][27];
bool f[27][27];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	cin >> s;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s1;
		f[s1[0]-'a'][s1[1]-'a']=f[s1[1]-'a'][s1[0]-'a']=true;
	}
	for (int i=0; i<maxn; i++) for (int j=0; j<27; j++) d[i][j]=inf;
	d[0][26]=0;
	for (int i=1; i<=(int)s.length(); i++) {
		for (int k=0; k<=26; k++) if (d[i-1][k]!=inf){
			if (!f[k][s[i-1]-'a']) d[i][s[i-1]-'a']=min(d[i][s[i-1]-'a'],d[i-1][k]);
			d[i][k]=min(d[i][k],d[i-1][k]+1);
		}
	}
	int ans=inf;
	for (int i=0; i<=26; i++) ans=min(ans,d[s.length()][i]);
	cout << ans;
	return 0;
}