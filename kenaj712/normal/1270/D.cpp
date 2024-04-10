#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main()
{
	int a,d;
	cin>>a>>a;
	a++;
	for(int x=1;x<=a;x++)
    {
        cout<<"? ";
        for(int y=1;y<=a;y++)
            if(y!=x)
                cout<<y<<" ";
        cout<<'\n';
        cout.flush();
        cin>>d>>d;
        m[d]++;
    }
    cout<<"! "<<(*m.rbegin()).second;
}