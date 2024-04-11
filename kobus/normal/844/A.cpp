#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int v[1123];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin>>s;

	int n;
	cin>>n;

	for(int i=0;i<s.size();i++){
		v[s[i]-'a']++;
	}
	int mk=0;
	for(int i=0;i<30;i++){
		if(v[i]!=0){
			v[mk]=v[i];
			mk++;
		}
	}
	if(mk>=n){
		cout<<"0\n";
		return 0;
	}
	if(s.size()<n){
		cout<<"impossible\n";
		return 0;
	}
	cout<<n-mk<<endl;

	return 0;
}