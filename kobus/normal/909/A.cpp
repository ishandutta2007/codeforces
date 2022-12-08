#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

string v[1123456];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1,s2;
	int counter=0;

	cin>>s1>>s2;

	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			for(int k=0;k<i;k++)v[counter]+=s1[k];
			for(int k=0;k<j;k++)v[counter]+=s2[k];
			counter++;
		}
	}

	sort(v,v+counter);

	cout<<v[0]<<endl;

	return 0;
}