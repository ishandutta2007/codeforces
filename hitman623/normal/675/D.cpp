#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,x,i;
    set < long long > s;
    set < long long > :: iterator it;
    map < long  long , long  long > parent,occr,occl;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        s.insert(x);
        if(i==0) continue;
        it=s.find(x);
        if(it==s.begin()) {it++;occl[*it]=1;}
        else if(++it==s.end()) {it--;it--;occr[*it]=1;}
        else
        {
            it--;
            it--;
            if(occr[*it]==1)
            {
                it++;it++;
                occl[*it]=1;
            }
            else
            {
                occr[*it]=1;
            }
        }
        parent[x]=*it;
        cout<<parent[x]<<" ";
    }
    return 0;
}