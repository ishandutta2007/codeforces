#include<bits/stdc++.h>
using namespace std;
int t,n;
int now;
int visit[100001];
int seq[100001];
int ans[100001];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		now=1;
		memset(visit,0,sizeof visit);
		for(int i=1;i<=n;i++){
			cin>>seq[i];
		}
		for(int i=1;i<=n;i++){
			if(seq[i]<now){
				cout<<-1<<'\n';
				goto tag;
			}
			if(seq[i]==seq[i-1]){
				ans[i]=now;
				visit[now]=1;
				while(visit[now]==1)now++;
			}
			else{
				ans[i]=seq[i];
				visit[seq[i]]=1;
				while(visit[now]==1)now++;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
		tag:;
	}
	return 0;
}