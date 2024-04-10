#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s[100500];


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s+1;
		string res;
		for(i=1;i<=n;i++){
			if(i==1&&s[i]>s[i+1]){
				continue;
			}
			if(i>1&&s[i]>=s[i+1]){
				continue;
			}
			else break;
		}
		if(i>n)i=n;
		for(j=1;j<=i;j++){
			res+=s[j];
		}
		for(j=i;j>=1;j--){
			res+=s[j];
		}
		cout<<res<<'\n';
	}
}