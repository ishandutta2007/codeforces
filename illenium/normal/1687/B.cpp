#include<bits/stdc++.h>
using namespace std;
#define N 555
typedef long long ll;
int n,m;
int Ask(string s){
	cout<<"? "<<s<<endl;
	int x;
	cin>>x;
	return x;
}
int p[N],w[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		string tmp(m,'0');
		tmp[i]='1';
		w[i]=Ask(tmp);
		p[i]=i;
	}
	sort(p,p+m,[&](int i,int j){return w[i]<w[j];});
	int ans=0;
	string tmp(m,'0');
	for(int i=0;i<m;++i){
		int u=p[i];
		tmp[u]='1';
		int z=Ask(tmp);
		if(z==ans+w[u]){
			ans+=w[u];
		}
		else{
			tmp[u]='0';
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;
}