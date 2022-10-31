#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,t,a[300500],res[300500],dis[300500],l,r;
 
vector<int> v[300500];
set<int> tmp;
 
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		tmp.clear();
		for(i=1;i<=n;i++){
			v[i].clear();
			res[i]=0;
			dis[i]=-1;
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			v[a[i]].push_back(i);
		}
		tmp.insert(0);
		tmp.insert(n+1);
		dis[0]=1145141919;
		for(i=1;i<=n;i++){
			for(j=0;j<v[i].size();j++){
				auto aaa=tmp.upper_bound(v[i][j]);aaa--;
				l=*(aaa);aaa++;
				r=*(aaa);
				tmp.insert(v[i][j]);
				dis[i]=max(dis[i],r-l-2);
				//printf("%d %d %d\n",l,r,v[i][j]);
			}
			dis[i]=min(dis[i],dis[i-1]);
		}
		for(i=1;i<=n;i++){
			if(dis[n+1-i]>=(i-1)){printf("1");}
			else{printf("0");}
		}puts("");
	}
}