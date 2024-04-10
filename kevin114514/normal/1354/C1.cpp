#include<bits/stdc++.h>
#define pi 3.1415926535
using namespace std;
const double val=pi/180.0;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		double X;
		cin>>X;
		double Ans=0;
		X*=2;
		double Angle=(X-2.0)*180.0/X;
		X/=4;
		X--;
		Angle=180.0-Angle;
		for(int i=1;i<=(int)(X);i++)
		{
			double Deg=Angle*i;
			Deg=90.0-Deg;
			double Tmp=sin(Deg*val);
			Ans+=Tmp;
		}
		Ans*=2.0;
		Ans+=1.0;
		printf("%.9lf\n",Ans);
	}
	return 0;
}