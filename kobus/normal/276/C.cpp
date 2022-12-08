#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX;
#define MOD 1000000007


int v[212345];
int ps[212345];
int s[212345];



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<q;i++){
		int com,fim;
		cin>>com>>fim;
		ps[com-1]++;
		ps[fim]--;
	}
	s[0]=ps[0];
	for(int i=1;i<n;i++)s[i]=s[i-1]+ps[i];
	sort(s,s+n);
	sort(v,v+n);
	int resp=0;
	for(int i=0;i<n;i++){
		//cout<<s[i]<<endl;
		resp+=s[i]*v[i];
	}
	cout<<resp<<endl;
	

	return 0;
}