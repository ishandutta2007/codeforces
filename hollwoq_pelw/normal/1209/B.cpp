#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int a[n],b[n],f[n];
	for (int i = 0; i < n; i++){ 
	    f[i]=s[i]-'0';
		cin >> a[i] >> b[i];
	}
	int ans=accumulate(f,f+n,0);
	for(int i = 0; i < 100000; i ++) {
		for (int j = 0; j < n; j++) {
		    if (i>=b[j]&&(i-b[j])%a[j]==0){ 
		        f[j]^=1;
		    }
		}
		ans=max(ans,accumulate(f,f+n,0));
	}
	cout << ans;
}