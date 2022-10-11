#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
int main(){
	int n,k,i,g=0;
	string s;
	cin>>n>>k;
	cin >> s;
	bool f;
	i=0;
	while(i<=n-k){
		f=1;
		int j=i;
		for (; j<i+k; j++){
			if (s[j]!=s[i]){
				f=0;
				break;
			}
		}
		if (f){
			m[s[i]]++;
			if (m[s[i]]>g){
				g=m[s[i]];
			}
		}
		i=j;
	}
	cout <<g;
	return 0;
}