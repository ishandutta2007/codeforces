#include<bits/stdc++.h>
using namespace std;
vector<int> polaczenia[100005];
int _size[100005];
bool odw[100005];
int tab2[100005];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    if(a%2==1)
    {
        cout<<-1;
        return 0;
    }
    int c,d;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        polaczenia[c].push_back(d);
        polaczenia[d].push_back(c);
    }
    int pom=0;
    for(int x=1;x<=a;x++)
    {
        _size[x]=polaczenia[x].size();
        if(_size[x]==1)
            q.push(x);
    }

    while(q.empty()==false)
    {
        int pom2=q.front();
        //cout<<pom2<<'\n';
        odw[pom2]=true;
        q.pop();
        if(_size[pom2]!=0)
        {
        if(tab2[pom2]%2==1)
        {
            pom++;
            for(int x=0;x<polaczenia[pom2].size();x++)
                if(odw[polaczenia[pom2][x]]==false)
                {
                    _size[polaczenia[pom2][x]]--;
                    if(_size[polaczenia[pom2][x]]==1)
                        q.push(polaczenia[pom2][x]);
                }

        }
        else
        {
            for(int x=0;x<polaczenia[pom2].size();x++)
            {
                if(odw[polaczenia[pom2][x]]==false)
                {
                    _size[polaczenia[pom2][x]]--;
                    tab2[polaczenia[pom2][x]]++;
                    if(_size[polaczenia[pom2][x]]==1)
                        q.push(polaczenia[pom2][x]);
                    /*else
                    {
                        if(tab2[polaczenia[pom2][x]]%2==0)
                            q.push(polaczenia[pom2][x]);
                        else
                        {
                            if(_size[polaczenia[pom2][x]]==1)
                            {
                                pom++;
                                odw[polaczenia[pom2][x]]=true;
                            }

                        }
                    }*/


                }
            }
        }
        }

    }
    cout<<pom;

	return 0;
}