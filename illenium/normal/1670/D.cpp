#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> A;
void Solve(){
	cin>>n;
	cout<<lower_bound(A.begin(),A.end(),n)-A.begin()+1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[3]={0,0,0};
	for(int t=1;;++t){
		++a[t%3];
		A.push_back(2*(a[0]*a[1]+a[0]*a[2]+a[1]*a[2]));
		if(A.back()>1e9)break;
	}
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}