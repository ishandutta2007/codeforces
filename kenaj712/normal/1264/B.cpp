#include<bits/stdc++.h>
using namespace std;
long long tab[5];
long long tab2[5];
vector<int> v;
bool czy=false;
void solve(int a,int b)
{
    long long suma=0,suma2;
    if(tab[a]==0)
        return;
    for(int x=0;x<4;x++)
    {
        suma+=tab[x];
        tab2[x]=tab[x];
    }
    suma2=suma;
    int where=a;
    while(suma--)
    {
        tab2[where]--;
        v.push_back(where);
        if(where-1!=-1 && tab2[where-1]>0 &&where-1!=b)
            where--;
        else if(where+1!=4&&tab2[where+1]>0&&where+1!=b)
            where++;
        else if(where-1!=-1 && tab2[where-1]>0)
            where--;
        else if(where+1!=4&&tab2[where+1]>0)
            where++;
        else
            break;
    }
    if(suma2==v.size())
    {
        czy=true;
        cout<<"YES"<<'\n';
        for(auto x:v)
            cout<<x<<" ";
    }
    v.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>tab[0]>>tab[1]>>tab[2]>>tab[3];
    for(int x=0;x<4;x++)
        for(int y=0;y<4;y++)
            if(czy==false)
                solve(x,y);
    if(czy==false)
        cout<<"NO";
	return 0;
}