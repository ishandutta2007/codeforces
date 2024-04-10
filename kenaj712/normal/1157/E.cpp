#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
multiset<int> s;
multiset<int>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    for(int x=0;x<a;x++)
    {
        cin>>b;
        s.insert(b);
    }
    for(int x=0;x<a;x++)
    {
        it=s.lower_bound(a-tab[x]);
        if(it==s.end())
            it=s.begin();
        cout<<(tab[x]+(*it))%a<<" ";
        s.erase(s.find(*it));
    }
	return 0;
}