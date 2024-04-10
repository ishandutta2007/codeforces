#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int num2;
	int val;
}x[200005];
bool cmp(node a,node b){
	return a.val>b.val;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i].val;
			x[i].num2=0;
			while(x[i].val%2==0){
				x[i].val/=2;
				x[i].num2++;
			}
		}
		sort(x,x+n,cmp);
		int ans=0;
		int tmp=0;
		for(int i=0;i<n;i++){
			if(i==0){
				tmp=x[0].num2;
				continue;
			}
			if(x[i].val==x[i-1].val){
				tmp=max(tmp,x[i].num2);
			}
			else{
				ans+=tmp;
				tmp=x[i].num2;
			}
		}
		cout<<ans+tmp<<'\n';
	}
	
    return 0;
}