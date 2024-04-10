#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s;
int a[666];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s1,s2,s3;
		cin>>s1>>s2;
		memset(a,0,sizeof(a));
		for(auto i:s2){
			a[i]++;
		}
		reverse(s1.begin(),s1.end());
		for(auto j:s1){
			if(a[j]){
				a[j]--;
				s3+=j;
			}
		}
		reverse(s3.begin(),s3.end());
		if(s3==s2){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}