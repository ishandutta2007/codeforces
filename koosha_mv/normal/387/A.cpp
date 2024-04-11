#include<iostream>
using namespace std;
int cr(float k)
{
	int t=1;
	while(k/10.0>=1)
	{
		k=k/10.0;
		t++;
	}
	return t;
}
int c(int h1,int m1,int h2,int m2)
{
	int h=h1-h2,m=m1-m2;
	if(m<0)
	{
		return((h-1)*100)+60+m;
	}
	return(h*100+m);
	
}
int a(int k)
{
	if(cr(k)==1)
		cout<<"00:0"<<k%10;
	if(cr(k)==2)
		cout<<"00:"<<k/10%10<<k%10;
	if(cr(k)==3)
		cout<<"0"<<(k/100)%10<<":"<<k/10%10<<k%10;
	if(cr(k)==4)
		cout<<k/100<<":"<<k/10%10<<k%10;
}
int main()
{
	string t1,t2;
	int h1,h2,m1,m2;
	cin>>t1;
	cin>>t2;
	h1=(((int(t1[0]))-48)*10)+((int(t1[1]))-48);
	m1=(((int(t1[3]))-48)*10)+((int(t1[4]))-48);
	h2=(((int(t2[0]))-48)*10)+((int(t2[1]))-48);
	m2=(((int(t2[3]))-48)*10)+((int(t2[4]))-48);
	//cout<<h1<<" "<<m1<<" "<<h2<<" "<<m2;
	int h;
	h=h1-h2;
	if(h1*100+m1>=h2*100+m2)
		a(c(h1,m1,h2,m2));
	else
	{
		int u;
		u=c(h2,m2,h1,m1);
		a(c(24,0,u/100,u%100));
	}
}