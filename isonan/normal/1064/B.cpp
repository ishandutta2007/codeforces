#include <iostream>

int t,a;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		std::cin>>a;
		int tem=__builtin_popcount(a);
		std::cout<<(1<<tem)<<std::endl;
	}
}