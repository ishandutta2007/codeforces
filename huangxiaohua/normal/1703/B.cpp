#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];
string s;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		set<char> st;
		for(auto i:s)st.insert(i);
		cout<<n+st.size()<<endl;
	}
}