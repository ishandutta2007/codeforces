#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

struct str{
	double first;
	double second;
	int index;
}x[200010];
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
std::vector<str> P,St;
 
int CCW(str A, str B, str C)
{
	/*
	printf("%lf %lf!\n",A.first,A.second);
	printf("%lf %lf!!\n",B.first,B.second);
	printf("%lf %lf!!!\n",C.first,C.second);
	*/
	double s1 = A.first*B.second + B.first * C.second + C.first * A.second;
	double s2 = A.second*B.first + B.second * C.first + C.second * A.first;
	if(s1>s2) return 1;
	if(s1<s2) return -1;
	return 0;
}

std::map< std::pair<double,double>, std::vector<int> > M;
int check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	
	for(int i=1;i<=a;i++)
	{
		double b,c;
		scanf("%lf%lf",&b,&c);
		M[std::make_pair(1/b,1/c)].push_back(i);
		x[i]={(double)1/b,(double)1/c,i};
	}
	std::sort(x+1,x+a+1,cmp);
	double max = x[1].second;
	P.push_back(x[1]);
	for(int i=2;i<=a;i++)
	{
		if(x[i].second<max)
		{
			P.push_back(x[i]);
			max = x[i].second;
		}
	}
	if(P.size()<=1)
	{
		std::vector<int> V = M[std::make_pair(P[0].first,P[0].second)];
		for(int j=0;j<V.size();j++) check[V[j]] = 1;
		for(int i=1;i<=a;i++) if(check[i]==1) printf("%d ",i);
		return 0;
	}
	else
	{
		St.push_back(P[0]);
		St.push_back(P[1]);
		for(int i=2;i<P.size();i++)
		{
			while(St.size()>=2)
			{
				str A = St[St.size()-1];
				str B = St[St.size()-2];
				if(CCW(B,A,P[i])<0) St.pop_back();
				else break;
			}
			St.push_back(P[i]);
		}
		for(int i=0;i<St.size();i++)
		{
			std::vector<int> V = M[std::make_pair(St[i].first,St[i].second)];
			for(int j=0;j<V.size();j++) check[V[j]] = 1;
		}
		//for(int i=0;i<St.size();i++) check[St[i].index] = 1;
		for(int i=1;i<=a;i++) if(check[i]==1) printf("%d ",i);
	}
}