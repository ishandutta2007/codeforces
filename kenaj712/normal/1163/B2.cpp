#include<bits/stdc++.h>
using namespace std;
int odw[1000005];
multiset<int> s;
multiset<int>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,maks=1,pocz,kon;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>b;
        if(odw[b]!=0)
            s.erase(s.find(odw[b]));
        odw[b]++;
        s.insert(odw[b]);
        if(s.size()==1)
        {
            maks=x;
            continue;
        }
        if(*s.begin()==1)
        {
            it=s.begin();
            it++;
            pocz=*it;
            it=s.end();
            it--;
            kon=*it;
            if(pocz==kon)
                maks=x;
        }
        it=s.end();
        it--;
        pocz=*s.begin();
        kon=*it;
        if(kon-pocz==1)
        {
            it--;
            kon=*it;
            if(pocz==kon)
                maks=x;
            it=s.begin();
            it++;
            pocz=*it;
        }
    }
    cout<<maks;

	return 0;
}