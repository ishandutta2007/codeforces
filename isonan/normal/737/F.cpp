#include <cstdio>
#include <vector>
#include <algorithm>

int n,s[2001],a,b,tem[3][2001],top[3];
std::vector<std::pair<int,int> >vec,vec2,ans;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	for(int i=n;i;i--){
		int j=i;
		while(j>1&&s[j-1]==s[j]-1)--j;
		vec.push_back(std::make_pair(s[i],i-j+1));
		i=j;
	}
	int nowmx=n;
	for(;!vec.empty();){
//		printf("%d %d\n",nowmx,vec.back().first);
		if(nowmx==vec.back().first){
			nowmx-=vec.back().second;
			for(int i=1;i<=vec.back().second;i++)ans.push_back(std::make_pair(1,1));
			for(int i=1;i<=vec.back().second;i++)ans.push_back(std::make_pair(2,1));
			vec.pop_back();
		}
		else{
			int i=vec.size()-1,j=i,sum=vec[i].second;
			while(j&&vec[j-1].first<vec[j].first)sum+=vec[--j].second;
			bool hole=0;
			for(int k=j;k<i;k++)hole|=(vec[k].first+vec[k+1].second!=vec[k+1].first);
//			printf("%d %d %d\n",i,j,sum);
			if(hole){
				if(sum>a){
					puts("NO");
					return 0;
				}
				else{
					ans.push_back(std::make_pair(1,sum));
					for(int k=j;k<=i;k++)vec2.push_back(vec[k]);
					for(int k=j;k<=i;k++)vec.pop_back();
				}
			}
			else{
				int mx=0;
				for(int k=j;k<=i;k++)mx=std::max(mx,vec[k].second);
				if(mx<=a&&sum<=b){
					for(int k=i;k>=j;k--)ans.push_back(std::make_pair(1,vec[k].second)),vec2.push_back(vec.back()),vec.pop_back();
				}
				else if(i-j+1==1){
					for(int k=sum-1;~k;k--)ans.push_back(std::make_pair(1,1)),vec2.push_back(std::make_pair(vec[i].first-k,1));
					vec.pop_back();
				}
				else if(i-j+1>2){
					if(sum>a){
						puts("NO");
						return 0;
					}
					else{
						ans.push_back(std::make_pair(1,sum));
						for(int k=j;k<=i;k++)vec2.push_back(vec[k]);
						for(int k=j;k<=i;k++)vec.pop_back();
					}
				}
				else{
					int l=vec[i].second,r=vec[j].second;
					if(std::max(0,std::max(l-b,r+l-a))<=std::min(a,b-r)){
						int I=std::max(0,std::max(l-b,r+l-a));
						if(I)ans.push_back(std::make_pair(1,I));
						if(I)vec2.push_back(std::make_pair(vec[j].first+I,I));
						vec2.push_back(vec[j]);
						ans.push_back(std::make_pair(1,sum-I));
						if(I<l)vec2.push_back(std::make_pair(vec[i].first,l-I));
						vec.pop_back();vec.pop_back();
					}
					else if(std::max(0,std::max(r-b,r+l-a))<=std::min(a,b-l)){
						int I=std::max(0,std::max(r-b,r+l-a));
						ans.push_back(std::make_pair(1,sum-I));
						if(I)ans.push_back(std::make_pair(1,I));
						if(I<r)vec2.push_back(std::make_pair(vec[j].first-I,r-I));
						vec2.push_back(vec[i]);
						if(I)vec2.push_back(std::make_pair(vec[j].first,I));
						vec.pop_back();vec.pop_back();
					}
					else{
						puts("NO");
						return 0;
					}
				}
			}
		}
		for(;!vec2.empty();){
			bool cando=0;
			for(int k=vec2.size()-1,sum=0;~k;--k){
				sum+=vec2[k].second;
				if(vec2[k].first==nowmx){
					if(sum>b){
						puts("NO");
						return 0;
					}
					nowmx-=sum;
					ans.push_back(std::make_pair(2,sum));
					vec2.resize(k);
					cando=1;
					break;
				}
				else if(k&&vec2[k].first+vec2[k-1].second!=vec2[k-1].first)break;
			}
			if(!cando)break;
		}
//		puts("*");
//		for(int i=0;i<ans.size();i++)
//			printf("%d %d\n",ans[i].first,ans[i].second);
//		puts("");
//		for(int i=0;i<vec.size();i++)
//			printf("%d %d\n",vec[i].first,vec[i].second);
//		puts("");
//		for(int i=0;i<vec2.size();i++)
//			printf("%d %d\n",vec2[i].first,vec2[i].second);
//		puts("*");
	}
	if(!vec2.empty()){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",ans.size());
	top[0]=n;
	for(int i=1;i<=n;i++)tem[0][i]=s[n-i+1];
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
		if(ans[i].second>(ans[i].first==1?a:b))puts("wrong");
		for(int j=1;j<=ans[i].second;j++)
			tem[ans[i].first][top[ans[i].first]+j]=tem[ans[i].first-1][top[ans[i].first-1]+j-ans[i].second];
		top[ans[i].first-1]-=ans[i].second;
		top[ans[i].first]+=ans[i].second;
	}
	if(top[0]||top[1])puts("wrong");
	for(int i=1;i<=n;i++)if(tem[2][i]!=n-i+1)puts("wrong");
}