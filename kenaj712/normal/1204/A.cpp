#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    if(a=="0")
    {
        cout<<0;
        return 0;
    }
    string b=a;
    while(b.back()=='0')
        b.pop_back();
    int pom=(a.size()+1)/2;
    if(a.size()%2==1&&b.size()==1)
        pom--;
    cout<<pom;
	return 0;
}