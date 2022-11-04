#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=202;
string s[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>s[i];
		if(s[0][1]==s[1][0]){
			if(s[n-1][n-2]==s[n-2][n-1]){
				if(s[0][1]!=s[n-1][n-2]){
					cout<<0<<endl;
					continue;
				}else{
					cout<<2<<endl;
					cout<<"1 2\n2 1\n";
					continue;
				}
			}else{
				cout<<1<<endl;
				if(s[n-1][n-2]==s[0][1]){
					cout<<n<<" "<<n-1<<endl;
					continue;
				}else{
					cout<<n-1<<" "<<n<<endl;
					continue;
				}
			}
		}
		if(s[n-1][n-2]==s[n-2][n-1]){
			cout<<1<<endl;
			if(s[n-1][n-2]==s[0][1]){
				cout<<1<<" "<<2<<endl;
				continue;
			}else{
				cout<<2<<" "<<1<<endl;
				continue;
			}
		}
		cout<<2<<endl;
		if(s[0][1]=='1')cout<<"1 2\n";
		if(s[1][0]=='1')cout<<"2 1\n";
		if(s[n-1][n-2]=='0')cout<<n<<" "<<n-1<<endl;;
		if(s[n-2][n-1]=='0')cout<<n-1<<" "<<n<<endl;;
	}
}