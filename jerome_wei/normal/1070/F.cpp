#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;

int stk[4][N],tp[4];
int ans,m,l,r;
int cnt=0;
priority_queue<int>pq;

int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int tpy,v;scanf("%d%d",&tpy,&v);
		if(tpy==11)tpy=3;
		if(tpy==10)tpy=2;
		stk[tpy][++tp[tpy]]=v;
	}
	for(int i=0;i<=3;i++){
		sort(stk[i]+1,stk[i]+tp[i]+1);
	}
	for(int i=tp[3];i;i--){
		ans+=stk[3][i];
		m++,l++,r++;
		cnt++;
	}
	while(tp[2]&&tp[1]){
		ans+=stk[2][tp[2]--];
		ans+=stk[1][tp[1]--];
		l++,r++,m+=2;
	}
	while(tp[2]){
		pq.push(stk[2][tp[2]--]);
	}
	while(tp[1]){
		pq.push(stk[1][tp[1]--]);
	}
	while(tp[0]){
		pq.push(stk[0][tp[0]--]);
	}
	while(!pq.empty()){
		if(cnt==0)break;
		ans+=pq.top();pq.pop();
		cnt--;
	}
	printf("%d\n",ans);
}