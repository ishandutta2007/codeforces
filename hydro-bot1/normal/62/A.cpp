// Hydro submission #63454d8b8d8541e8893397bb@1665486219791
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
	int al,ar,bl,br;
    cin>>al>>ar>>bl>>br;
    if((al*2+3>br&&br>=al-1)||(ar*2+3>bl&&bl>=ar-1))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
	return 0;
}