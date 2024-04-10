#include<bits/stdc++.h>
using namespace std;
vector<int> fil;
vector<int> v1;
vector<int> v2;
vector<int> v3;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    string b,c;
    cin>>b>>c;
    for(int x=1;x<=a;x++)
    {
        if(b[x-1]=='0'&&c[x-1]=='0')
            fil.push_back(x);
        if(b[x-1]=='1'&&c[x-1]=='0')
            v1.push_back(x);
        if(b[x-1]=='0'&&c[x-1]=='1')
            v2.push_back(x);
        if(b[x-1]=='1'&&c[x-1]=='1')
            v3.push_back(x);
    }
    int licz1=0,licz2=0,licz3=0,licz4=0,t=v3.size();
    while(t--)
    {
        if(licz1+v1.size()<=licz2+v2.size())
            licz1++;
        else
            licz2++;
    }
    while(v1.size()+licz1-licz4>v2.size()+licz2)
        licz4++;
    while(v1.size()+licz1<v2.size()+licz2-licz3)
        licz3++;
    if(v1.size()+licz1+licz3>a/2||v2.size()+licz2+licz4>a/2||(v3.size()%2==1&&v1.size()==0&&v2.size()==0))
    {
        cout<<-1;
        return 0;
    }
    for(int x=0;x<v1.size()-licz4;x++)
        cout<<v1[x]<<" ";
    for(int x=0;x<licz1;x++)
        cout<<v3[x]<<" ";
    for(int x=0;x<licz3;x++)
        cout<<v2[x]<<" ";
    int pom=a/2-v1.size()+licz4-licz1-licz3;
    for(int x=0;x<pom;x++)
        cout<<fil[x]<<" ";
	return 0;
}