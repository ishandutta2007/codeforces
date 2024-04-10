#include<bits/stdc++.h>
using namespace std;

const int mn = 2e5+10;
int a[mn];

bool test(int n,int rem){
	for(int i=0,j=n-1;i<j;){
		if(a[i]==rem){
			i++;
			continue;
		}
		if(a[j]==rem){
			j--;
			continue;
		}
		if(a[i]!=a[j])return 0;
		++i,--j;
	}
	return 1;
}

void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)cin>>a[i];
	int rema=-1,remb=-1;
	for(int i=0,j=n-1;i<j;++i,--j){
		if(a[i]!=a[j]){
			rema=a[i];
			remb=a[j];
			break;
		}
	}
	printf("%s\n",(test(n,rema)||test(n,remb)) ? "YES" : "NO");
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}