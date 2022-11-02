#include<bits/stdc++.h>
using namespace std;
vector<int> v;
queue<int> q;
int tab[1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        if(d!=a)
        {
            cout<<"NO";
            return 0;
        }
        v.push_back(-c);
    }
    sort(v.begin(),v.end());
    for(int x=0;x<a-1;x++)
    {
        v[x]=-v[x];
        tab[v[x]]++;
    }
    int licz=0,last;
    bool czy=false;
    for(int x=a-1;x>0;x--)
    {
        licz+=tab[x]-1;
        if(tab[x]>1&&czy==false)
        {
            czy=true;
            last=x;
        }

        if(licz<0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    int last2=a;
    for(int x=a-1;x>0;x--)
    {
        if(tab[x]==1)
            cout<<a<<" "<<x<<'\n';
        else if(tab[x]>1)
        {
            if(q.empty()==true)
                last=x;
            int pom=tab[x]-1;
            while(pom--)
                q.push(x);
        }
        else
        {
            /*if(last==q.front())
            {
                cout<<last2<<" "<<x<<'\n';
                last2=x;
                q.pop();
            }
            else
            {
                cout<<last2<<" "<<last<<'\n';
                last=q.front();
                cout<<a<<" "<<x<<'\n';
                q.pop();
                last2=x;
            }*/
            cout<<last2<<" "<<x<<'\n';
            last2=x;
            q.pop();
            if(q.empty()==true)
            {
                cout<<last2<<" "<<last<<'\n';
                last2=a;
            }
            else if(q.front()!=last)
            {
                 cout<<last2<<" "<<last<<'\n';
                 last2=a;
                 last=q.front();
            }

        }
    }


	return 0;
}