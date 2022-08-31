#include <cstdio>
#include <vector>

std::vector<std::pair<int,int> >vec;
std::vector<int>row,col;
int n,a[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i;i--){
		if(a[i]==0){
			continue;
		}
		else if(a[i]==1){
			col.push_back(i);
//			row.push_back(n-i+1);
			vec.push_back(std::make_pair(n-i+1,i));
		}
		else if(a[i]==2){
			if(col.empty()){
				puts("-1");
				return 0;
			}
			vec.push_back(std::make_pair(n-col.back()+1,i));
			col.pop_back();
			row.push_back(i);
		}
		else{
			int v=-1;
			if(!row.empty())v=row.back(),row.pop_back();
			if(!~v&&!col.empty())v=col.back(),col.pop_back();
			if(!~v){
				puts("-1");
				return 0;
			}
			vec.push_back(std::make_pair(n-i+1,i));
			vec.push_back(std::make_pair(n-i+1,v));
			row.push_back(i);
		}
	} 
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++)printf("%d %d\n",n-vec[i].first+1,vec[i].second);
}