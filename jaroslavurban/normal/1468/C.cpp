#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int N=500100;
bool done[N];
int idd[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int q;cin>>q;
	priority_queue<pair<int,int>>pq;
	queue<int>qq;
	int curid=1;
	while(q--){
		int id;cin>>id;
		if(id==1){
			int money;cin>>money;
			pq.push({money,q});
			qq.push(q);
			idd[q]=curid++;
		}
		if(id==2){
			while(done[qq.front()])qq.pop();
			done[qq.front()]=1;
			cout<<idd[qq.front()]<<" ";
			qq.pop();
		}
		if(id==3){
			while(done[pq.top().second])pq.pop();
			done[pq.top().second]=1;
			cout<<idd[pq.top().second]<<" ";
			pq.pop();
		}
	}
	cerr<<endl;
}