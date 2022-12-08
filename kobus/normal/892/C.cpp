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
#define INF INT_MAX
#define MOD 1000000

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int v[2123];
int memo[2123][2123];
int pd(int com,int fim){
	if(com==fim)return v[com];
	if(memo[com][fim]==-1){
		memo[com][fim]=gcd(v[com],pd(com+1,fim));
	}
	return memo[com][fim];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	int num=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]==1)num++;
	}
	if(num!=0){
		cout<<n-num<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			memo[i][j]=-1;
		}
	}
	int mini=INF;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(pd(i,j)==1)mini=min(mini,j-i);
		}
	}
	if(mini==INF){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<mini+n-1-num<<endl;
	

	return 0;
}