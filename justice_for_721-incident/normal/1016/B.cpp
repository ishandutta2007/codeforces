#include<iostream>
using namespace std;
int n,m,q;
string s,t;
bool a[1001];
int sum[1001];
int main(){
	cin >> n >> m >> q;
	cin >> s >> t;
	s='?'+s;
	for(int i=1; i<=n-m+1 ;i++){
		a[i]=true;
		for(int j=0; j<t.size() ;j++){
			if(s[i+j]!=t[j]) a[i]=false;
		}
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1; i<=q ;i++){
		int l,r;
		cin >> l >> r;
		if(r-l+1<m){
			cout << "0\n";
			continue;
		}
		cout << sum[r-m+1]-sum[l-1] << '\n';
	}
}