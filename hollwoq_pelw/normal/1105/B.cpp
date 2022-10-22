#include<bits/stdc++.h>
using namespace std;

int n,k,len,nw,ans;
char s[201001];

int main(){
	cin >> n >> k;
	cin >> s; 
	ans=0;
	for (int j=0; j<26; j++){
		len=nw=0;
		for (int i=0; i<n; i++)
			if (s[i]!=j+'a') nw+=len/k,len=0;
			else len++;
		nw+=len/k;
		ans=max(ans,nw);
	}
	cout << ans;
	return 0;
}