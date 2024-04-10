#include <cstdio>
#include <cstdlib>
#include <algorithm>

std::vector<std::pair<int,int> >vec,ans;
int n,d[2001];
void wrong(){puts("-1");exit(0);}
void push(int s,int t){
	--vec[s].first,--vec[t].first;
	ans.push_back(std::make_pair(vec[s].second,vec[t].second));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",d+i),vec.push_back(std::make_pair(d[i],i));
	for(;;){
		std::sort(vec.begin(),vec.end(),std::greater<std::pair<int,int> >());
		while(!vec.empty()&&vec.back().first==0)vec.pop_back();
		if(vec.empty())break;
		int end=vec.size()-1,ind=0;
		if(vec[end].first==1){
			if(!end)wrong();
			for(int i=0;i<end;i++)
				if(vec[i].first%2&&vec[i].first>1){ind=i;break;}
			if(vec[ind].first==1&&end>1)wrong();
			push(end,ind);
		}
		else if(vec[end].first==2){
			if(vec.size()<3)wrong();
			if(vec[ind].first==2){
				for(int i=ind;i<end;i++)
					push(i,i+1);
				push(ind,end);
			}
			else{
				if(vec[end-1].first>2)wrong();
				push(end-1,end);
				push(end,ind);
				push(end-1,ind);
			}
		}
		else wrong();
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("2 %d %d\n",ans[i].first,ans[i].second);
}