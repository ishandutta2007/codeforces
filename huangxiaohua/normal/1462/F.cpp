#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int,int> mp1,mp2,mp3,mp4,mp5;

struct sb{
	int id,l,r;
}s[200500];

int i,n,t,j,k,res;
vector<int> v;
int main(){
	scanf("%d",&t);
	while(t--){
		mp1.clear();mp2.clear();
		mp3.clear();mp4.clear();mp5.clear();
		v.clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d",&s[i].l,&s[i].r);
			s[i].id=i;
			mp1[s[i].l]++;
			mp2[s[i].r]++;
			//l[i]=s[i].l;r[i]=s[i].r;
			if(!mp5[s[i].l]){v.push_back(s[i].l);mp5[s[i].l]=1;}
			if(!mp5[s[i].r]){v.push_back(s[i].r);mp5[s[i].r]=1;}
		}
		sort(v.begin(),v.end());
		for(i=0;i<v.size();i++){
			if(i==0){mp3[v[i]]=mp1[v[i]];}
			else{mp3[v[i]]=mp1[v[i]]+mp3[v[i-1]];}
			
			if(i==0){mp4[v[i]]=mp2[v[i]];}
			else{mp4[v[i]]=mp2[v[i]]+mp4[v[i-1]];}
			//printf("%d %d %d %d %d\n",v[i],mp1[v[i]],mp2[v[i]],mp3[v[i]],mp4[v[i]]);
		}
		res=0;
		for(i=1;i<=n;i++){
			//printf("%d\n",mp3[s[i].r]-mp4[s[i].l]+mp2[s[i].l]);
			res=max(res,mp3[s[i].r]-mp4[s[i].l]+mp2[s[i].l]);
		}
		printf("%d\n",n-res);
	}
}