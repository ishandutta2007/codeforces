#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],it;
ll res;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		if(k==-1){j=1;continue;}
		a[++it]=j*k;
	}
	priority_queue<int> q;
	res+=a[it];it--;
	while(it){
		n>>=1;
		for(i=1;i<=n;i++){q.push(-a[it]);it--;}
		res-=q.top();q.pop();
	}
	cout<<res;
}