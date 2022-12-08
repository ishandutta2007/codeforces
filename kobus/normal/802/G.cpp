#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int v[11234];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin>>s;

	string h="heidiA";
	int n=0;

	for(int i=0;i<s.length();i++){
		if(s[i]==h[n]){
			n++;
		}
	}

	if(n==5){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}