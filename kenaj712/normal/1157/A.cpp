#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int pom=0;
    while(0==0)
    {
        if(a==1)
            pom++;
        if(pom==5)
            break;
        s.insert(a);
        a++;
        while(a%10==0)
            a/=10;
    }
    cout<<s.size();
	return 0;
}