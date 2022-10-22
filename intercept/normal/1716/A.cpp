#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
void work(){
	int n;
	cin>>n;
	if(n==1)puts("2");
	else cout<<(n-1)/3+1<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}