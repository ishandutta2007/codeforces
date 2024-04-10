#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


unordered_map<int,vector<int> > mp;
int i,j,k,n,t,M;
ll sb,tmp1,tmp2;
vector<int> v;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main(){
	srand(time(0));
	scanf("%d%d%d",&tmp1,&tmp2,&M);
	for(i=1;i<=10000;i++){
		v.clear();sb=tmp1;t=100;
		while(t--){
			j=rand()%3+1;v.push_back(j);
			if(j==1){sb+=1;}
			if(j==2){sb-=1;}
			if(j==3){sb=ksm(sb,M-2);}
			if(!mp[sb].size()){mp[sb]=v;}
		}
	}
	while(1){
		v.clear();sb=tmp2;t=100;
		while(t--){
			j=rand()%3+1;v.push_back(j);
			if(j==1){sb+=1;}
			if(j==2){sb-=1;}
			if(j==3){sb=ksm(sb,M-2);}
			if(mp[sb].size()){
				printf("%d\n",mp[sb].size()+v.size());
				for(auto i:mp[sb]){
					printf("%d ",i);
				}
				for(int i=v.size()-1;i>=0;i--){
					printf("%d ",(v[i]==3)?3:3-v[i]);
				}
				return 0;
			}
		}
	}
}