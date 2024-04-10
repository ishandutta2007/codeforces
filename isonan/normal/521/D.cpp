#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int> >Add[100001];
std::vector<std::pair<double,int> >Mul[100001];
std::vector<std::pair<double,int> >tot,val;
std::vector<int>ans;
bool cmp(const std::pair<int,int> &a,const std::pair<int,int> &b){return (a.second<b.second)?1:(a<b);}
int k,n,m,a[100001],b[100001][2],T[100001],I[100001],B[100001];
int main(){
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++)scanf("%d",a+i);
	for(int i=1,T,I,B;i<=n;i++){
		scanf("%d%d%d",&T,&I,&B);
		::T[i]=T,::I[i]=I,::B[i]=B;
		if(T==1){
			if(b[I][0]<B)b[I][0]=B,b[I][1]=i;
		}
		else if(T==2){
			if(B>0)Add[I].push_back(std::make_pair(B,i));
		}
		else{
			if(B>1)Mul[I].push_back(std::make_pair((double)B,i));
		}
	}
	for(int i=1;i<=k;i++)if(b[i][0]>a[i])Add[i].push_back(std::make_pair(b[i][0]-a[i],b[i][1]));
	for(int i=1;i<=k;i++){
		std::sort(Add[i].begin(),Add[i].end());
		std::reverse(Add[i].begin(),Add[i].end());
//		for(int j=0;j<Add[i].size();j++)
//			printf("(%d %d)",Add[i][j].first,Add[i][j].second);
//		putchar('\n');
		std::sort(Mul[i].begin(),Mul[i].end());
		std::reverse(Mul[i].begin(),Mul[i].end());
	}
	int cnt=0;
	for(int i=1;i<=k;i++)cnt=Mul[i].size()+(Add[i][0].first>a[i]);
	for(int i=1;i<=k;i++){
		for(int j=0;j<Mul[i].size();j++)
			tot.push_back(Mul[i][j]);
		if(Add[i].size()&&Add[i][0].first>a[i])tot.push_back(std::make_pair((double)(a[i]+Add[i][0].first)/(double)a[i],Add[i][0].second));
	}
	std::sort(tot.begin(),tot.end());
	std::reverse(tot.begin(),tot.end());
	std::vector<std::pair<double,int> >Tot;
	for(int i=1;i<=k;i++){
		if(!Add[i].size())continue;
		long long val=a[i];
		for(int j=0;j<Add[i].size();j++){
			if(j||Add[i][0].first<=a[i])Tot.push_back(std::make_pair((double)(val+Add[i][j].first)/(double)val,Add[i][j].second));
			val+=Add[i][j].first;
		}
	}
	std::sort(Tot.begin(),Tot.end());
	std::reverse(Tot.begin(),Tot.end());
	tot.insert(tot.end(),Tot.begin(),Tot.end());
	if(tot.size()>m)tot.resize(m);
	printf("%d\n",tot.size());
	for(int i=0;i<tot.size();i++)if(T[tot[i].second]==1)printf("%d ",tot[i].second);
	for(int i=0;i<tot.size();i++)if(T[tot[i].second]==2)printf("%d ",tot[i].second);
	for(int i=0;i<tot.size();i++)if(T[tot[i].second]==3)printf("%d ",tot[i].second);
}