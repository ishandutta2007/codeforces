#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
int T,n,c,q,i,qwq,a[N];
ll sum,l[N],x,r[N],len[N];
string s;
char query(ll f1,ll f2){
	if(f1==0){
		return s[f2-1];
	}
	if(len[f1-1]>=f2){
		return query(f1-1,f2);
	}
	else{
		return query(f1-1,l[f1]+f2-len[f1-1]-1); 
	}
}
int main(){
	ios::sync_with_stdio(0); 
	cin>>T;
	while(T--){
		cin>>n>>c>>q>>s;len[0]=n;
		for(i=1;i<=c;++i)cin>>l[i]>>r[i],len[i]=len[i-1]+r[i]-l[i]+1;
		while(q--){
			cin>>x;
			cout<<query(c,x)<<"\n"; 
		}
	}
}