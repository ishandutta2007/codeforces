#include<iostream>
#include<algorithm>
using namespace std;
int g[101],b[101];
int main()
{
	int tb,tg;
	cin>>tb;	
	for(int i=0;i<tb;i++)
		cin>>b[i];
	cin>>tg;
	for(int i=0;i<tg;i++)
		cin>>g[i];
	sort(b,b+tb);
	sort(g,g+tg);
	int jb=0,jg=0,t=0;
	while(jb<tb && jg<tg)
	{
		if(b[jb]-g[jg]>1)
			jg++;
		if(g[jg]-b[jb]>1)
			jb++;
		if(g[jg]==b[jb] || g[jg]==b[jb]+1 || g[jg]+1==b[jb] )
		{
			t+=1;
			jb++;
			jg++;
		}
	}
	cout<<t;
}