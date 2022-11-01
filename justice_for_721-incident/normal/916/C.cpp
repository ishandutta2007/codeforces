#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,m;
int p=120889;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cout << p << ' ' << p << endl;
	for(int i=1; i<n-1 ;i++){
		cout << i << ' ' << i+1 << ' ' << 1 << endl;
	}
	cout << n-1 << ' ' << n << ' ' << p-n+2 << endl;
	m-=n-1;
	for(int i=1; i<=n ;i++){
		for(int j=i+2; j<=n ;j++){
			if(m==0) return 0;
			cout << i << ' ' << j << ' ' << p+1 << endl;
			m--;
			
		}
	}
}