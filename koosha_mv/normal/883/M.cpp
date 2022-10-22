#include<iostream>
using namespace std;
int ghadr(int n)
{
	if(n<0)
		return -1*n;
	return n;
}
int main()
{
	int x1,y1,x2,y2,e=0,b=1024;
	int j1[8]={1,1,1,-1,-1,-1,0,0},j2[8]={1,0,-1,1,0,-1,1,-1};
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i=0;i<8;i++)
	{
		e=0;
		e+=ghadr(x1-(x2+j1[i]))+ghadr(y1-(y2+j2[i]));
		b=min(e,b);
	}
	cout << b*2+8;
}