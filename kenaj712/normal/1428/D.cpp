#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> one;
vector<int> two;
vector<int> three;
int tab[1000005];
vector<pair<int,int>> out;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int row=a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    for(int x=a;x>=1;x--)
    {
        if(tab[x]==1)
        {
            out.push_back(make_pair(row,x));
            one.push_back(make_pair(row,x));;
            row--;
        }
        else if(tab[x]==2)
        {
            if(one.empty())
            {
                cout<<-1;
                return 0;
            }
            out.push_back(make_pair(one.back().first,x));
            one.pop_back();
            two.push_back(x);
        }
        else if(tab[x]==3)
        {
            if(two.empty() && one.empty() && three.empty())
            {
                cout<<-1;
                return 0;
            }
            if(!three.empty())
            {
                out.push_back(make_pair(row,x));
                out.push_back(make_pair(row,three.back()));
                three.pop_back();
                three.push_back(x);
            }
            else if(!two.empty())
            {
                out.push_back(make_pair(row,x));
                out.push_back(make_pair(row,two.back()));
                two.pop_back();
                three.push_back(x);
            }
            else
            {
                out.push_back(make_pair(row,x));
                out.push_back(make_pair(row,one.back().second));
                one.pop_back();
                three.push_back(x);
            }
            row--;
        }

    }
    cout<<out.size()<<'\n';
    for(auto x:out)
        cout<<x.first<<" "<<x.second<<'\n';
	return 0;
}