#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        if(b!=0)
            s.insert(b);
    }
    cout<<s.size();
	return 0;
}