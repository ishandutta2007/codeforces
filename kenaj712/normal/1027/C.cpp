#include<bits/stdc++.h>
using namespace std;
vector <int> v;
vector <int> v2;
int tab[10005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t,a,b,licz;
    bool czy;
    double mini,p,q;
    int w,e;
    cin>>t;
    while(t--)
    {
        cin>>a;
        czy=false;
        for(int x=0;x<a;x++)
        {
            cin>>b;
            v.push_back(b);
            tab[b]++;
            if(tab[b]==2)
                v2.push_back(b);
            if(tab[b]==4&&czy==false)
            {
                for(int y=0;y<4;y++)
                    cout<<b<<" ";
                cout<<'\n';
                czy=true;
            }

        }
        if(czy==true)
        {
            while(v.empty()==false)
            {
                tab[v[v.size()-1]]=0;
                v.pop_back();
            }
            v2.resize(0);
            continue;
        }
        mini=100000;
        sort(v2.begin(),v2.end());
        for(int x=0;x<v2.size()-1;x++)
        {
            p=v2[x],q=v2[x+1];
            if(p/q+q/p<mini)
            {
                mini=p/q+q/p;
                w=p;
                e=q;
            }
        }
        cout<<w<<" "<<w<<" "<<e<<" "<<e<<'\n';
        while(v.empty()==false)
            {
                tab[v[v.size()-1]]=0;
                v.pop_back();
            }
        v2.resize(0);
    }
	return 0;
}