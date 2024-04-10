#include<iostream>
using namespace std;
int n,m;
int a[101],b[101];
int ans[101][101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int tmp=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		tmp^=a[i];
	}
	for(int i=1; i<=m ;i++){
		cin >> b[i];
		tmp^=b[i];
	}
	if(tmp!=0){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i=1; i<n ;i++){
		for(int j=1; j<m ;j++){
			cout << 0 << ' ';
		}
		cout << a[i] << endl;
		tmp^=a[i];
	}
	for(int j=1; j<m ;j++){
		cout << b[j] << ' ';
	}
	cout << (tmp^b[m]) << endl;
}