#include<bits/stdc++.h>
using namespace std;
set<int> s;
bool f(int a)
{
    int pom=0,pom2;
    while(a!=0)
    {
        pom++;
        s.insert(a%10);
        a/=10;
    }

    pom2=s.size();
    s.clear();
    if(pom==pom2)
        return true;
    return false;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=a;x<=b;x++)
        if(f(x)==true)
    {
        cout<<x;
        return 0;
    }
    cout<<-1;
	return 0;
}