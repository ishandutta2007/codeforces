#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int readopt(){
	char x=0;while(x!='+'&&x!='-')x=getchar();
	return x=='+';
}
struct heap{
	priority_queue<int,vector<int>,greater<int> >M,D;
	inline void ins(int x){M.push(x);}
	inline void del(int x){D.push(x);}
	inline int top(){
		while(!D.empty()&&!M.empty()&&M.top()==D.top())M.pop(),D.pop();
		if(M.empty())return -1;
		else return M.top();
	}
}hep[40];
ll sub[40];
int tot=0;
int main()
{
	int T;cin>>T;
	while(T--){
		int opt=readopt();
		//cout<<opt<<endl;
		int x;scanf("%d",&x);
		int side=0;
		while((1<<side) < x)side++;
		if(opt==1){
			++tot;
			hep[side].ins(x);
			for(int i=side+1;i<=30;i++)sub[i]+=x;
		}else{
			--tot;
			hep[side].del(x);
			for(int i=side+1;i<=30;i++)sub[i]-=x;
		}
		int ret=tot;
		for(int i=0;i<=30;i++)if(hep[i].top()!=-1){
			int tmp=hep[i].top();
			//cout<<tmp<<" "<<sub[i]<<endl;
			if(tmp>2ll*sub[i]) ret--;
		}
		printf("%d\n",ret);
	}
}