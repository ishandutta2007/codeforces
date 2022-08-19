#include <cstdio>
#include <vector>

int n;
std::vector<int>a;
int solve(std::vector<int>&a,int d){
	if(!a.size())return 0;
	if(a.size()==1)return 1;
	std::vector<int>L,R;
	for(int i=0;i<a.size();i++)
		if(a[i]&(1<<d))L.push_back(a[i]);
		else R.push_back(a[i]);
	a.clear();
	bool bb1=(!R.empty()),bb2=(!L.empty()); 
	int v=std::max(solve(L,d-1)+bb1,solve(R,d-1)+bb2);
	return v;
}
int main(){
	scanf("%d",&n);
	a.resize(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	printf("%d\n",n-solve(a,30));
}