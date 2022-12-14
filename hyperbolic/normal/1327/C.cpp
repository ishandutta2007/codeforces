#include <stdio.h>
#include <vector>

std::vector<char> V;
std::pair<int,int> x[1010],y[1010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++) scanf("%d%d",&x[i].first,&x[i].second);
	for(int i=1;i<=c;i++) scanf("%d%d",&y[i].first,&y[i].second);
	if(a>1) for(int i=1;i<=a;i++) V.push_back('U');
	if(b>1) for(int i=1;i<=b;i++) V.push_back('L');
	for(int i=1;i<=a;)
	{
		for(int j=1;j<b;j++) V.push_back('R');
		V.push_back('D');
		i++;
		if(i>a) break;
		for(int j=1;j<b;j++) V.push_back('L');
		V.push_back('D');
		i++;
		if(i>a) break;
	}
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++) printf("%c",V[i]);
}