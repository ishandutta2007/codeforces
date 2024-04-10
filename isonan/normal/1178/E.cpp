#include <cstdio>
#include <vector>
#include <cstring>

char str[1000001];
std::vector<char>vec;
int main(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	int l=1,r=n;
	while(r-l+1>=4){
		if(str[l]==str[r]||str[l]==str[r-1])vec.push_back(str[l]);
		else vec.push_back(str[l+1]);
		l+=2,r-=2;
	}
	for(int i=0;i<vec.size();i++)putchar(vec[i]);
	if(l<=r)putchar(str[l]);
	for(int i=vec.size()-1;~i;--i)putchar(vec[i]);
}