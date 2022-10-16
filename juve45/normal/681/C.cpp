#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m, a, b, x;
string s;
vector <string> sol;
priority_queue <int, vector <int>, greater<int> > pq;

string iss(int c)
{
    
    string x, pl;
    if(c==0)
    {
    x="0";
    return x;
    }
    if(c<0)
    {
        pl="-";
        c=-c;
    }
    while(c!=0)
    {
        x+=char(c%10+'0');
        c/=10;
    }
    reverse(x.begin(), x.end());
    return pl+x;
}

void solveI()
{
    cin>>x;
    string s=iss(x);
    pq.push(x);
    sol.push_back("insert "+s);
}

void solveR()
{
    if(pq.empty())
    {
        sol.push_back("insert 0");
        pq.push(0);
    }
    sol.push_back("removeMin");
    pq.pop();
}


void solveG()
{
    cin>>x;
    string s=iss(x);
    if(!pq.empty() && pq.top()<x)
    {
        while(!pq.empty() && pq.top() < x)
        {
            pq.pop();
            sol.push_back("removeMin");
        }
    }
    if(pq.empty() || pq.top()!=x)
    {

        sol.push_back("insert " + s);
        pq.push(x);
    }
    sol.push_back("getMin "+s);

}

int main()
{
ios_base::sync_with_stdio(false);
cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s=="insert")
        {
            solveI();
        }
        else if(s=="removeMin")
        {
            solveR();
        }
        else solveG();
    }

    cout<<sol.size()<<'\n';

    for(int i=0;i<sol.size();i++)
    {
        cout<<sol[i]<<'\n';
    }

    return 0;
}