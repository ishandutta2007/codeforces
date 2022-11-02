#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c;
    cin>>a;
    int licz=0;
    for(int x=1;x<=a;x++)
    {
        cin>>c;
        s.insert(c);
        s.erase(x);
        if(s.size()==0)
            licz++;
    }
    cout<<licz;
	return 0;
}