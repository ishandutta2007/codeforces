#include<bits/stdc++.h>
using namespace std;

struct sb{
	int id,tp,len,num;
	bool operator< (const sb x)const{return num>x.num;}
}s,tmp;

unordered_map<int,unordered_map<int,int> > mp;
priority_queue<sb> q;
vector<int> v[200500];
int i,j,k,n,m,used[200500][55],u2[200500],res1[200500][55],res2[200500],x,y;

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
    	scanf("%d%d%d",&x,&y,&k);
    	mp[x][y]=mp[y][x]=k;
    	v[x].push_back(y);
    	v[y].push_back(x);
	}
	for(i=2;i<=n;i++){
		res2[i]=-1;
	}
	s.id=1;s.tp=2;
	q.push(s);
	while(!q.empty()){
		s=q.top();q.pop();
		if(s.tp==2){
			if(u2[s.id]){continue;}
			u2[s.id]=1;res2[s.id]=s.num;
			for(auto i:v[s.id]){
				if(!used[i][mp[s.id][i]]){
					tmp.id=i;tmp.tp=1;tmp.len=mp[s.id][i];tmp.num=res2[s.id]+tmp.len*tmp.len;
					q.push(tmp);
				}
			}
		}
		else{
			if(used[s.id][s.len]){continue;}
			used[s.id][s.len]=1;
			for(auto i:v[s.id]){
				if(!u2[i]){
					tmp.id=i;tmp.tp=2;tmp.num=s.num+mp[s.id][i]*mp[s.id][i]+2*mp[s.id][i]*s.len;
					q.push(tmp);
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",res2[i]);
	}
}