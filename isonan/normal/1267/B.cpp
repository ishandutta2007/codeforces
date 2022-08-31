#include <cstdio>
#include <cstring>
#include <vector> 

char str[300001];
int nl;
std::vector<std::pair<char,int> >vec;
int main(){
	scanf("%s",str+1);
	nl=strlen(str+1);
	for(int i=1,last=0;i<=nl;i++){
		if(i==nl||str[i]!=str[i+1]){
			vec.push_back(std::make_pair(str[i],i-last));
			last=i;
		}
	}
	if(vec.size()%2==0){puts("0");return 0;}
	else{
		int siz=vec.size();
		if(vec[siz>>1].second<2){puts("0");return 0;}
		for(int i=0;i<(siz>>1);i++){
			if(vec[i].first!=vec[siz-i-1].first||vec[i].second+vec[siz-i-1].second<3){puts("0");return 0;}
		}
		printf("%d\n",vec[siz>>1].second+1);
	}
}