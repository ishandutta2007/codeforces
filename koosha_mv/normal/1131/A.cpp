#include<iostream>
using namespace std;
int main()
{
	int h1,h2,w1,w2;
	cin>>w1>>h1>>w2>>h2;
	cout<<4+((h1+h2)*2)+((max(w1,w2)*2));
}