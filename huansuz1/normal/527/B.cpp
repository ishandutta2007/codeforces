#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
	int a[26][26];
	string s,t;
	int ans=0;
	int n;
	
int main(){
	cin>>n;
	cin>>s>>t;
	for (int i=1;i<=n;i++) {
		if (s[i-1]!=t[i-1]) {
			int x=int(t[i-1]-'a');
			int y=int(s[i-1]-'a');
			a[x][y]=i;
			ans++;
		}
	}
	for (int i=0;i<26;i++) {
		for (int j=0;j<26;j++) {
			if (a[i][j]!=0 && a[j][i]!=0) {
				cout<<ans-2<<endl;
				cout<<a[i][j]<<" "<<a[j][i];
				return 0;
			}
		}
	}
	for (int i=0;i<26;i++) {
		if (a[i][i]==0) {
			int x=0,y=0;
			for (int j=0;j<26;j++)
				x=max(a[j][i],x);
			for (int j=0;j<26;j++)
				y=max(a[i][j],y);
			if (x!=0 && y!=0){
				cout<<ans-1<<endl;
				cout<<x<<" "<<y;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	cout<<-1<<" "<<-1;
	return 0;
}