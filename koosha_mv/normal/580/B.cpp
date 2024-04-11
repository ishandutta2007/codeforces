#include<iostream>
#include<algorithm>
using namespace std;
pair<long long,long long> p[100001];
int main(){
	long long n,d;
	cin>>n>>d;
	long long q,w; 
	for(long long i=0;i<n;i++){
		cin>>q>>w;
		p[i].first = q;
		p[i].second = w; 
	}
	sort(p,p+n);
	long long s1=0,s2=0,maxx=0,maxxx=p[0].second;
	maxx=p[0].second;
	while(s2<n)
	{
		if(p[s2].first-p[s1].first<d){
			//cout<<s1<<"  "<<s2<<"  "<<maxx<<endl;
			maxxx=max(maxxx,maxx);
			s2++;
			maxx+=p[s2].second;
		}
		else
		{
			maxx-=p[s1].second;
			s1++;
		}
	}
	cout<<maxxx;
	}