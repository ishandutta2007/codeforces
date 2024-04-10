#include <cstdio>
#include <vector>

int n;
std::vector<std::pair<int,int> >ope;
std::vector<int>vec[15001];
void Do(int x,int y){
	ope.push_back(std::make_pair(x,y));
}
void solve(int l,int r,int ind){
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid,ind);
	solve(mid+1,r,ind);
	for(int i=l;i<=mid;i++)Do(vec[ind][i],vec[ind][i-l+mid+1]);
}
int main(){
	scanf("%d",&n);
	int top=0,cnt=0;
	for(;n;n-=n&-n){
		++top;
		for(int i=1;i<=(n&-n);i++)vec[top].push_back(++cnt);
	}
	for(int i=1;i<=top;i++){
		solve(0,vec[i].size()-1,i);
	}
	int now=1;
	while(now<top-1){
		std::vector<int>tem;
		for(int i=0;i<vec[now].size();i++)tem.push_back(vec[top].back()),vec[top].pop_back();
		for(int i=0;i<vec[now].size();i++)Do(vec[now][i],tem[i]);
		for(int i=0;i<tem.size();i++)vec[now].push_back(tem[i]);
		while(vec[now].size()==vec[now+1].size()){
			for(int i=0;i<vec[now].size();i++)Do(vec[now][i],vec[now+1][i]);
			for(int i=0;i<vec[now].size();i++)vec[now+1].push_back(vec[now][i]);
			++now; 
		}
//		printf("%d %d %d\n",vec[now].size(),vec[now+1].size(),vec[top].size());
	}
	printf("%d\n",ope.size());
	for(int i=0;i<ope.size();i++)printf("%d %d\n",ope[i].first,ope[i].second);
}