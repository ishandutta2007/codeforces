#include<cstdio>
#include<algorithm>

using namespace std;

int tab[1007];

bool przec(int a, int b)
{
	int x1 = min(tab[a-1], tab[a]),
			x2 = max(tab[a-1], tab[a]),
			x3 = min(tab[b-1], tab[b]),
			x4 = max(tab[b-1], tab[b]);
	if(x1 < x3 && x3 < x2 && x2 < x4)
		return true;
	if(x3 < x1 && x1 < x4 && x4 < x2)
		return true;
	return false;
}

bool check(int n)
{
	for(int i=1; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(przec(i,j))
				return true;
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &tab[i]);
	puts(check(n) ? "yes" : "no");
}