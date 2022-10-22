#include<iostream>
#include<vector>
using namespace std;
int s=0,v[300009],mark[300009],x,y,t1,t2,e1=1e6;
vector<int> e[300009];
int dp(int x){
	//cout<<"X:"<<x<<" "<<endl;
	int d1=0,d2=0,d;
	mark[x]=1;
	for(int i=0;i<e[x].size();i++){
		if(mark[e[x][i]]==0){
			d=dp(e[x][i]);
			d1+=d/e1;
			d2+=d%e1;
		}
	}
	if(v[x]==1) d1++;
	if(v[x]==2) d2++;
	if((d1==t1 && d2==0) || (d2==t2 && d1==0))
		s++;
	return d1*e1+d2;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(v[i]==1) t1++;
		if(v[i]==2) t2++;
	}
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		e[x-1].push_back(y-1);
		e[y-1].push_back(x-1);
	}
	//for(int i=0;i<n;i++){
	//	for(int j=0;j<e[i].size();j++)
	//		cout<<e[i][j]<<" ";
	//	cout<<endl;
	//}
	dp(0);
	cout<<s;
}