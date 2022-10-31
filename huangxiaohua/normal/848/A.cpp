#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==0){
		cout<<"nmsl";
		return 0;
	}
	for(t='a';n;t++){
		for(i=0;;i++){
			if(i>n)break;
			s+=(char)(t);
			n-=i;
		}
	}
	cout<<s;
	if(n)return 1;
}