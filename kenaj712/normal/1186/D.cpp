#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool odw[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    double b;
    long long suma=0;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        if(int(b)==b)
        {
            odw[x]=true;
            v.push_back(int(b));
            continue;
        }

        if(b<0)
            v.push_back(int(b)-1);
        else
            v.push_back(int(b));
    }
    for(auto x:v)
        suma+=x;
    int gdzie=0;
    for(auto x:v)
    {
        if(odw[gdzie]==true)
        {
            cout<<x<<'\n';
            gdzie++;
            continue;
        }
        if(suma<0)
        {
            cout<<x+1;
            suma++;
        }
        else
            cout<<x;
        gdzie++;
        cout<<'\n';
    }





	return 0;
}