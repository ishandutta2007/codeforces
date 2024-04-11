#include<iostream>
using namespace std;
int koochik(int q,int w,int e)
{
	if(q<=e && q<=w)
		return q;
	if(w<=e && w<=q)
		return w;
	return e;
}
int main()
{
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	cout << koochik(n1/1,n2/2,n3/4)*7;
}