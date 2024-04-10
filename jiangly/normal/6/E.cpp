//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int>h(n);
	for(int i=0;i<=n-1;++i){
		scanf("%d",&h[i]);
	}
	int Len=0;
	vector<int>Ans;
	deque<int>QM,Qm;
	for(int i=0,j=0;i<=n-1;++i){
		while(!QM.empty()&&h[QM.back()]<=h[i]){
			QM.pop_back();
		}
		QM.push_back(i);
		while(!Qm.empty()&&h[Qm.back()]>=h[i]){
			Qm.pop_back();
		}
		Qm.push_back(i);
		while(h[QM.front()]-h[Qm.front()]>k){
			j=min(QM.front(),Qm.front())+1;
			QM.front()<Qm.front()?QM.pop_front():Qm.pop_front();
		}
		if(i-j+1>Len){
			Len=i-j+1;
			Ans.clear();
			Ans.push_back(i);
		}else if(i-j+1==Len){
			Ans.push_back(i);
		}
	}
	int Cnt=Ans.size();
	printf("%d %d\n",Len,Cnt);
	for(auto i:Ans){
		printf("%d %d\n",i-Len+2,i+1);
	}
	return 0;
}