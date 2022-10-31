#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[100500],sb;

map<int,int> mp;
void add(int x){
	sb-=(mp[a[x]]==2);
	mp[a[x]]--;
	a[x]++;
	mp[a[x]]++;
	sb+=(mp[a[x]]==2);
}
void del(int x){
	sb-=(mp[a[x]]==2);
	mp[a[x]]--;
	a[x]--;
	mp[a[x]]++;
	sb+=(mp[a[x]]==2);
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<< ((a[1]&1)?"sjfnb":"cslnb") ;return 0;
	}
	
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		mp[a[i]]++;
		if(mp[a[i]]==2)sb++;
	}
	
	//cout<<sb<<endl;
	for(i=1;i<=n;i++){
		if(!a[i])continue;
		del(i);
		if(!sb){
			//cout<<i<<endl;
			add(i);goto aaa;
		}
		add(i);
	}
	
	cout<<"cslnb";
	return 0;
	
	aaa:;
	ll res=0;
	for(i=1;i<=n;i++){
		res+=a[i]-i+1;
	}
	cout<<((res&1)?"sjfnb":"cslnb");
}