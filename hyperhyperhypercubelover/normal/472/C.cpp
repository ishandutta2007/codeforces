#include<iostream>
#include<string>

std::string a[100000];
std::string b[100000];
int p[100000];

int main()
{
	std::string t;
	int i,n;
	std::cin>>n;
	for(i=0;i<n;i++)std::cin>>a[i]>>b[i];
	for(i=0;i<n;i++)
	{
		std::cin>>p[i];
		p[i]--;
	}
    for(i=0;i<n;i++)
	{
		if(a[p[i]]<t&&b[p[i]]<t)break;
		else if(a[p[i]]>t&&b[p[i]]<t)t=a[p[i]];
		else if(a[p[i]]<t&&b[p[i]]>t)t=b[p[i]];
		else
		{
			if(a[p[i]]<b[p[i]])t=a[p[i]];
			else t=b[p[i]];
		}
	}
	std::cout<<(i<n?"NO":"YES");
}