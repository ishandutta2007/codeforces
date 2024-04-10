#include <cstdio>
#include <vector>

long long T;
int stk[51],top,ans;
std::vector<int>vec[4];
void add_barrier(int x1,int y1,int x2,int y2){
	if(!x1||x1>ans||!y1||y1>ans||!x2||x2>ans||!y2||y2>ans)return;
	vec[0].push_back(x1);
	vec[1].push_back(y1);
	vec[2].push_back(x2);
	vec[3].push_back(y2);
}
int main(){
	scanf("%I64d",&T);
	while(T)stk[++top]=T%6,T/=6;
	ans=(top+1)<<1;
	add_barrier(1,2,2,2);
	add_barrier(2,1,2,2);
	for(int now=2;top;--top,now+=2){
		add_barrier(now-2,now+3,now-1,now+3);
		add_barrier(now,now+2,now,now+3);
		add_barrier(now+1,now+2,now+1,now+3);
		add_barrier(now,now+4,now+1,now+4);
		add_barrier(now+3,now-2,now+3,now-1);
		add_barrier(now+2,now,now+3,now);
		add_barrier(now+2,now+1,now+3,now+1);
		add_barrier(now+4,now,now+4,now+1);
		add_barrier(now-1,now+1,now,now+1);
		if(stk[top]>2)stk[top]-=3;
		else add_barrier(now+1,now-1,now+1,now);
		if(stk[top]>0)--stk[top];
		else add_barrier(now-1,now+2,now,now+2);
		if(stk[top]>0)--stk[top];
		else add_barrier(now+2,now-1,now+2,now);
	}
	printf("%d %d\n",ans,ans);
	printf("%d\n",vec[0].size());
	for(int i=0;i<vec[0].size();i++,putchar('\n'))
		for(int j=0;j<4;j++)printf("%d ",vec[j][i]);
}