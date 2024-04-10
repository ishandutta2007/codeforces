#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int book[n+5];
	for(int i=1;i<=n;i++)cin>>book[i];
	int lar=-1,now=1,cnt=0;
	while(now<=n){
		lar=book[now];
		cnt++;
		while(now<lar){
			now++;
			lar=max(lar,book[now]);
		}
		lar=-1;
		now++;
	}
	cout<<cnt<<endl;
	return 0;
}