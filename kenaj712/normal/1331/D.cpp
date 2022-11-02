#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    if(a.back()>='0' && a.back()<='9')
        cout<<(a.back()-'0')%2;
    else
        cout<<(a.back()-'A')%2;
	return 0;
}