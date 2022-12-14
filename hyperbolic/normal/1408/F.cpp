#include <stdio.h>
#include <vector>

void func(int L, int R, std::vector< std::pair<int,int> > &V)
{
	if(L==R) return;
	
	int h = (L+R)/2;
	std::vector< std::pair<int,int> > V1,V2;
	func(L,h,V1);
	func(h+1,R,V2);
	for(int i=0;i<V1.size();i++) V.push_back(V1[i]);
	for(int i=0;i<V2.size();i++) V.push_back(V2[i]);
	for(int i=L;i<=h;i++) V.push_back(std::make_pair(i,i-L+h+1));
}

std::vector< std::pair<int,int> > V1,V2;
int main()
{
	int a;
	scanf("%d",&a);
	if(a<=2)
	{
		printf("0");
		return 0;
	}
	
	int C;
	for(int i=1;;i*=2)
	{
		if(i>a)
		{
			C = i/2;
			break;
		}
	}
	
	func(1,C,V1);
	func(a-C+1,a,V2);
	printf("%d\n",V1.size()+V2.size());
	for(int i=0;i<V1.size();i++) printf("%d %d\n",V1[i].first,V1[i].second);
	for(int i=0;i<V2.size();i++) printf("%d %d\n",V2[i].first,V2[i].second);
}