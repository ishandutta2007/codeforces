#include <bits/stdc++.h>

int n;
char str[11];
bool Q(std::vector<int>vec){
	printf("? %d",vec.size());
	for(int v:vec)printf(" %d",v);putchar('\n');
	fflush(stdout);
	static char str[11];
	scanf("%s",str);
	return str[0]=='Y';
}
bool G(int x){
	printf("! %d\n",x);
	fflush(stdout);
	scanf("%s",str);
	return str[1]==')';
}
int main(){
	scanf("%d",&n);
	std::vector<int>vec;
	for(int i=1;i<=n;++i)vec.push_back(i);
	for(;vec.size()>3;){
		int mid=vec.size()>>1;
		std::vector<int>L,R,t1,t2;
		for(int i=0;i<mid;++i)L.push_back(vec[i]);
		for(int i=mid;i<vec.size();++i)R.push_back(vec[i]);
		if(Q(R))std::swap(L,R);
		int mid2=R.size()>>1;
		for(int i=0;i<mid2;++i)t1.push_back(R[i]);
		for(int i=mid2;i<R.size();++i)t2.push_back(R[i]);
		if(Q(t2))std::swap(t1,t2);
		vec=L;
		for(int v:t1)vec.push_back(v);
	}
	if(vec.size()==1){
		G(vec[0]);
		return 0;
	}
	if(vec.size()==2){
		if(!G(vec[0]))G(vec[1]);
		return 0;
	}
	if(vec.size()==3){
		for(int i=0;i<3;++i){
			std::vector<int>tem;
			tem.push_back(vec[i]);
			bool bb=Q(tem);
			if(!bb)bb=Q(tem);
			if(bb){
				if(!G(vec[i])){
					std::vector<int>tem;
					for(int j=0;j<3;++j)if(i!=j)tem.push_back(vec[j]);
					std::vector<int>tem2;
					tem2.push_back(tem[0]);
					G(tem[Q(tem2)?0:1]);
				}
				return 0;
			}
			else{
				std::vector<int>tem;
				for(int j=0;j<3;++j)if(i!=j)tem.push_back(vec[j]);
				if(!G(tem[0]))G(tem[1]);
				return 0;
			}
		}
	}
}