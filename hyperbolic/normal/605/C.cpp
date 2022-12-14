#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::map< std::pair<int,int> , int> check;
std::vector< std::pair<double,double> > V,P;

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

double y[100010],z[100010];
int main()
{
	int a,p,q;
	scanf("%d%d%d",&a,&p,&q);
	
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		int g = gcd(d,e);
		if(check.find(std::make_pair(d/g,e/g))==check.end()) check[std::make_pair(d/g,e/g)] = e;
		else if(check[std::make_pair(d/g,e/g)]<e) check[std::make_pair(d/g,e/g)] = e;
	}
	for(std::map< std::pair<int,int> , int> ::iterator it = check.begin();it!=check.end();it++)
	{
		P.push_back(std::make_pair(-(double)((it->first).first)/((it->first).second),(double)1/(it->second)));
	}
	std::sort(P.begin(),P.end());
	
	for(int i=0;i<P.size();i++)
	{
		double x1,x2;
		std::pair<double,double> V1,V2;
		
		while(V.size()>=2)
		{
			V1 = V[V.size()-1];
			V2 = V[V.size()-2];
			
			x1 = (V1.second-P[i].second)/(P[i].first-V1.first);
			x2 = (V2.second-V1.second)/(V1.first-V2.first);
			if(x1<x2) break;
			else V.pop_back();
		}
		V.push_back(P[i]);
		u:;
	}
	
	
	double ans = 0;
	for(int i=0;i<V.size()-1;i++)
	{
		double x1 = (V[i].second-V[i+1].second)/(V[i+1].first-V[i].first);
		double y1 = x1*V[i].first + V[i].second;
		if(x1<0 || y1<0) continue;
		double k = p*x1 + q*y1;
		ans = ans>k?ans:k;
	}
	
	for(int i=0;i<V.size()-1;i++)
	{
		y[i] = (V[i].second-V[i+1].second)/(V[i+1].first-V[i].first);
		z[i] = y[i]*V[i].first + V[i].second;
	}
	
	int L = V.size()-1;
	if(V.size()>=2) for(int i=V.size()-2;i>=0;i--) if(y[i]<0) L = i;
	int R = 0;
	if(V.size()>=2) for(int i=0;i<=V.size()-2;i++) if(z[i]<0) R = i+1;
	
	double x1 = -V[R].second/V[R].first;
	double y1 = 0;
	double k =p*x1+q*y1;
	ans = ans>k?ans:k;
	
	x1 = 0;
	y1 = V[L].second;
	k = p*x1 + q*y1;
	ans = ans>k?ans:k;
	printf("%.12lf",ans);
}