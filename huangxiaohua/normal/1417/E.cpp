#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define cnm(x) x.pre=(x.num&(1<<(t-2)))>0
int i,j,t,n,zero,one,k;
ll d[31][2],res;
struct sb{
	int num;
	bool pre;
}a;
 
vector<sb> vv;
void dp(int t,vector<sb> v){
	if(v.size()<=1||!t){vector<sb>().swap(v);return;}
	n=v.size();
	one=zero=0;
	
	vector<sb> v0,v1;
	
	if(v[0].pre){one++;cnm(v[0]);v1.push_back(v[0]);}
	else{zero++;cnm(v[0]);v0.push_back(v[0]);}
	
	for(i=1;i<n;i++){
		if(v[i].pre){
			one++;d[t][1]+=zero;
			cnm(v[i]);
			v1.push_back(v[i]);
		}
		else{
			zero++;d[t][0]+=one;
			cnm(v[i]);
			v0.push_back(v[i]);
		}
	}
	vector<sb>().swap(v);
	dp(t-1,v0);dp(t-1,v1);
}
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a.num);
		a.pre=(a.num&(1<<29))>0;
		vv.push_back(a);
	}
	dp(30,vv);
	for(i=1;i<=30;i++){
		if(d[i][1]<d[i][0]){k+=(1<<(i-1));res+=d[i][1];}
		else{res+=d[i][0];}
	}
	printf("%lld %d\n",res,k);
}